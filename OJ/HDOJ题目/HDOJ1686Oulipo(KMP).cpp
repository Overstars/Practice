#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char w[10005],t[1000005];
int nex[10005];//nex[i]��¼w[0:i]������󹫹�������
void getnext(char *B,int n)
{
	nex[0]=0;
	for(int i=1,j=0;i<n;i++)/* nΪB������ */
	{
//		j=nex[i-1];jΪ������λǰһλ��Ӧ����󹫹�������һλ(��ǰһλ��Ӧ����󹫹�������)
		while(B[j]!=B[i]&&j>0)//��ƥ�䲻��,������С�����Ӵ�,��ΪB��i֮ǰ��j���ַ�(B[i-j]~B[i-1])�뿪ͷ��j��(B[0]~B[j-1])��ͬ,ֱ����ǰ��j���ַ�����
			j=nex[j-1];//����󹫹��Ӵ�����һλ��B[i]��ͬ����󹫹��Ӵ�,������j--,��֤B[0]��B[i-1]���Ŀǰƥ��ǰ׺��׺ʼ����ͬ
		if(B[j]==B[i])//��������һλ�ַ���ͬ���������+1
			j++;
		nex[i]=j;//jΪ0~i��󹫹�������,������B[j]!=B[i],j=0
	}
}//https://www.cnblogs.com/c-cloud/p/3224788.html
int kmp(int m,int n)//mΪA������,nΪB������
{
	int ans=0,cmp=0;
	for(int i=0;i<m;i++){
		while(cmp>0&&t[i]!=w[cmp])//��cmp��λ��ƥ��ʧ��
			cmp=nex[cmp-1];//��һ�ִ�ƥ��ɹ�������󹫹�������һλ��ʼƥ��
		if(t[i]==w[cmp])//��ǰ�ַ�ƥ��ɹ�,������һλ
			cmp++;
		if(cmp==n){//�Ӵ�ƥ��ɹ�
			ans++;
			cmp=nex[cmp-1];//����ĸ���ָ�����ּ�����й�������
		}
	}
	return ans;
}
int main()
{
	int n;
	cin>>n;
	getchar();
	while(n--){
		gets(w);
		gets(t);
		getnext(w,strlen(w));
		printf("%d\n",kmp(strlen(t),strlen(w)));
	}
	return 0;
}
