#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int inf=0x3f3f3f3f;
char s[1000005];
int nex[1000005];
void getnex(int n)
{
	nex[0]=0;
	for(int i=1,j=0;i<n;i++)
	{
		j=nex[i-1];
		while(j>0&&s[i]!=s[j])
			j=nex[j-1];
		if(s[i]==s[j])
			j++;
		nex[i]=j;
	}
}
int kmp(int n)
{
	getnex(n);
	int len=n-nex[n-1];//最小循环串长度
	if(n%len==0)
	{
		return n/len;
	}
	return 1;
}
int main()
{
	while(scanf("%s",s)==1&&s[0]!='.'){
		cout<<kmp(strlen(s))<<endl;
	}
	return 0;
}
