#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=1e6+5;
int sa[MAXN],rak[MAXN],height[MAXN],tp[MAXN],tax[MAXN];
//sa[����]=���:��i���ĺ�׺�Ǵ�sa[i]��ʼ(�±�)
//rak[���](a[i])=����:��i�ź�׺������Ϊrak[i]
//tp[i](b[i]):�ڶ��ؼ���Ϊi�ĺ�׺����tp[i]��ʼ(�±�)
//tax[i]:��һ�ؼ���Ϊi������tax[i]��(��������ʱ�õ�Ͱ)
char s[MAXN];
int len,m;//lenΪs����,mΪ����������Ͻ�
void rsort(int a[],int b[])//aΪ��һ�ؼ�������,bΪ�ڶ��ؼ���
{
	for(int i=0;i<=m;i++)//����m��Ͱ
		tax[i]=0;//Ͱ���
	for(int i=1;i<=len;i++)
		tax[a[i]]++;//ÿ�����Ž��Լ���Ͱ
	for(int i=1;i<=m;i++)
		tax[i]+=tax[i-1];//ÿһ�����Ͱ����ǰ���Ͱ
	for(int i=len;i>=1;i--)
		sa[tax[a[b[i]]]--]=b[i];
}
bool comp(int r[],int a,int b,int k)
{//ͨ����Ԫ�������±�ıȽϣ�ȷ�������Ӵ��Ƿ���ͬ
    return r[a]==r[b]&&r[a+k]==r[b+k];
}
void get_sa(int a[],int b[])//a/b:ָ��rak��tp��ָ��
{
	for(int i=1;i<=len;i++)
		m=max(m,a[i]=s[i]-'0'),b[i]=i;
	rsort(a,b);//�ȶ�ÿ����׺���׸��ַ����ֵ�������
	for(int p=0,j=1;p<len;j<<=1,m=p)//jΪ��������
	{//Len����׺�����Ȳ�ͬ,һ���ֳܷ��Ⱥ�
		p=0;//p��ʾ��ͬ��׺������
		for(int i=1;i<=j;i++)//��j����׺û�еڶ��ؼ���,������ǰ��
			b[++p]=len-j+i;
		for(int i=1;i<=len;i++)
			if(sa[i]>j)
				b[++p]=sa[i]-j;
		rsort(a,b);//�µ���ɢ��,ֱ������������ͬʱ����
		swap(a,b);//����ָ��rak��tp��ָ��
		a[sa[1]]=p=1;//��һ���ĵ�һ�ؼ�����1
        for(int i=2;i<=len;i++)//��һ����֮ǰ����ͬ����,�����ź���
			a[sa[i]]=comp(b,sa[i],sa[i-1],j)?p:++p;//������������������Ӵ�
    }
}
void getheight()
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
int main()
{
    scanf("%s",s+1);
    len=strlen(s+1);//���������ĳ���
    get_sa(rak,tp);
//    cout<<"sa:"<<endl;
    for(int i=1;i<=len;i++)
		printf("%d ",sa[i]);
}

