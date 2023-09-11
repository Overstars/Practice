#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
const int inf=0x3f3f3f3f;
const int mod=10007;
char str[200005];
int nex[200005];//KMP��next[i]Ϊt[0:i]�����ǰ���Ӵ�����
void getnex(int n)
{
	nex[0]=0;
	for(int i=1,j=0;i<n;i++)
	{
		while(j>0&&str[i]!=str[j])
			j=nex[j-1];
		if(str[i]==str[j])
			j++;
		nex[i]=j;
	}
//	for(int i=0;i<n;i++)
//	{
//		printf("�±�:%d,nex[i]=%d\n",i,nex[i]);
//	}
}
int main()//������ǰ׺����ƥ�����
{
	int t,n;
	cin>>t;
	while(t--)
	{
		scanf("%d %s",&n,str);
		getnex(n);
		int ans=n;//ÿ�������Լ�ƥ��
		for(int i=1;i<n;i++)
		{
			int t=nex[i];
			while(t)
			{
				ans=(ans+1)%mod;//
				t=nex[t-1];//ת�Ƶ��±�Ϊ����������-1��ʼƥ��
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
