#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=1e6+5;
int sa[MAXN],rak[MAXN],height[MAXN],tp[MAXN],tax[MAXN];
//sa[����]=���:��i���ĺ�׺�Ǵ�sa[i]��ʼ(�±�)
//rak[���](a[i])=����:��i�ź�׺������Ϊrak[i]
//height[i]:����i-1��i��������׺���������ǰ׺����
//tp[i](b[i]):�ڶ��ؼ���Ϊi�ĺ�׺����tp[i]��ʼ(�±�)
//tax[i]:��һ�ؼ���Ϊi������tax[i]��(��������ʱ�õ�Ͱ)
char str[MAXN];
int len,m;//lenΪs����,mΪ����������Ͻ�
void rsort(int a[],int b[])//aΪ��һ�ؼ�������(��һ�ε�rank),bΪ�ڶ��ؼ�������i��λ��
{
	for(int i=0;i<=m;i++)//����m��Ͱ
		tax[i]=0;//Ͱ���
	for(int i=1;i<=len;i++)
		tax[a[i]]++;//ÿ����һ�ؼ��ַŽ��Լ���Ͱ
	for(int i=1;i<=m;i++)
		tax[i]+=tax[i-1];//ǰ׺��:ÿһ�����Ͱ����ǰ���Ͱ,���ٵĶ�λ��ÿ��λ��Ӧ�е�����
//ǰ׺�Ϳ���ͳ�Ʊȵ�ǰ����С�ĺ�׺�ж��ٸ�
	for(int i=len;i>=1;i--)
		sa[tax[a[b[i]]]--]=b[i];//�����µ�����
}
//�����Ѿ��õ���w���ȵ�������Ҫ����2w���ȵ�����
//sa[i]������Ϊw�ĺ�׺�У�����Ϊi�ĺ�׺��λ��
//a[i]:����Ϊw�ĺ�׺�У��ӵ�i��λ�ÿ�ʼ�ĺ�׺������(a[λ��]=����)
//b[i]:����Ϊ2w�ĺ�׺�У��ڶ��ؼ�������Ϊi�ĺ�׺��λ��(b[����]=λ��)
//i�Ӵ�Сö�ٵڶ��ؼ���b[i],����a[i]��λ����һ�ؼ�������
//��һ�ؼ������˳�򲻱�,��b����ȷ��a��ͬ�ĺ�׺�������λ��
bool comp(int r[],int a,int b,int k)
{//˫�ؼ�����ɢ,ȷ�������Ӵ��Ƿ���ͬ
	return r[a]==r[b]&&r[a+k]==r[b+k];
}//s[i:i+2w]������������һ�ֵ�s[i:i+w]��s[i+w:i+2w]�����ۺϵó�
//����s[i:i+w]�������������������ɵ�a[i]��
//����true˵��s[i:i+w]
void get_sa(char s[],int a[],int b[])//s:ָ��str��ָ��,a/b:ָ��rak��tp��ָ��
{
	for(int i=1;i<=len;i++)
		m=max(m,a[i-1]=s[i]-s[i-1]+88),b[i]=i;
	rsort(a,b);//�ȶ�ÿ����׺���׸��ַ����ֵ�������
	for(int p=0,j=1;p<len;j<<=1,m=p)//jΪ��������
	{//Len����׺�����Ȳ�ͬ,һ���ֳܷ��Ⱥ�
		p=0;//����p�Ǽ�����
		//��ʼ�Եڶ��ؼ��ֽ�������,b[����]=λ��
		for(int i=1;i<=j;i++)//��j����׺û�еڶ��ؼ���,������ǰ��
			b[++p]=len-j+i;
		for(int i=1;i<=len;i++)//sa[i]:��һ�������Ľ��
			if(sa[i]>j)//��j���ĺ�׺���еڶ��ؼ���
				b[++p]=sa[i]-j;//1.���������źõ�˳�� 2.
		//�ڶ��ؼ����������
		rsort(a,b);//�µ���ɢ��,ֱ������������ͬʱ����ѭ��
		swap(a,b);//����b����û��,����Ҫʹ��a������һ�ֵ�a
		//��ʱa��������һ�ֵ�һ�ؼ�������,b�Ǳ��ֵ�һ�ؼ�������
		a[sa[1]]=p=1;//��һ���ĵ�һ�ؼ�����1,p��ʾ��ͬ��׺������
		for(int i=2;i<=len;i++)//��ǰ����֮ǰ����ͬ����,�����ź���
			a[sa[i]]=comp(b,sa[i],sa[i-1],j)?p:++p;//������������������Ӵ�
    }//a[λ��]=��һ�ֵ�һ�ؼ�������,b[λ��]=���ֵ�һ�ؼ�������,sa[����]=λ��
}

void getheight(char s[])
{//height[i]:����Ϊ i �ĺ�׺������Ϊ i-1 �ĺ�׺���� LCP
	for(int i=1;i<=len;i++)//����sa���rak(��һ���Լ�����ȥ��)
		rak[sa[i]]=i;
	for(int i=1,j=0;i<=len;i++)
	{
		if(j)
			j--;
		while(s[i+j]==s[sa[rak[i]-1]+j])
			j++;
		height[rak[i]]=j;
	}
}
bool judge(int len,int n)//���Եĳ���
{
	int M=sa.sa[0],m=sa.sa[0];//sa[����]=�±�
	for(int i=1;i<n;i++)
	{
		if(sa.height[i]>=len)//�����˹������ȴ���mid�ĺ�׺��,�ж��Ƿ��ص�
			M=max(M,sa.sa[i]),m=min(m,sa.sa[i]);//����ʹ���ηֵıȽ�Զ,�ܴ���len
		else//����һ�������¿�ʼѰ�ҹ�����>=len�����κ�׺��
			M=sa.sa[i],m=sa.sa[i];
		if(M-m>len)//�����ڵĻ�,��ԭ�������ص�
			return 1;
	}
	return 0;
}
int main()
{
	int ans=0,n,maxi;
	while(cin>>len&&len)
	{
//		sa.clear();
		if(len==1)
		{
			puts("0");
			continue;
		}
		maxi=ans=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&sa.s[i]);
			if(i){
				sa.s[i-1]=sa.s[i]-sa.s[i-1]+88;
				maxi=max(maxi,sa.s[i-1]);
			}
		}
		sa.s[n-1]=0;
		sa.n=n;
		sa.build_sa(maxi+1);
		sa.build_height();
		int left=0,right=n-1,mid;
		while(left<=right)
		{
			mid=(left+right)>>1;
			if(judge(mid,n))
				left=mid+1,ans=max(ans,mid);//�ڳ�����������Ҹ��Ž�
			else
				right=mid-1;
//			printf("l=%d,r=%d,ans=%d\n",left,right,ans);
		}
		if(ans>=4)
			cout<<ans+1<<endl;//��¼��ֵ,Ҫ+1
		else
			cout<<0<<endl;
	}
	return 0;
}

