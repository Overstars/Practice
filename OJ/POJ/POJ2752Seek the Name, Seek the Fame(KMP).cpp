#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
using namespace std;
#define PI 3.14159265358979323846
#define e  2.7182818284590452354
#define ln_2 0.69314718055994530942
#define ln_10 2.30258509299404568402
const int inf=0x3f3f3f3f,maxn=400005;
char s[maxn];
int nex[maxn],ans[maxn];
void getnex(char *s,int n)
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
int main()
{
	while(cin>>s)
	{
		int p,len=strlen(s),cnt=0;
		getnex(s,len);
		stack<int> XOX;
		XOX.push(len);
		p=len-1;
		while(nex[p]>0)
		{//短一点的公共串一定是最大公共子串的最大公共子串
			XOX.push(nex[p]);
			p=nex[p]-1;
		}
		while(!XOX.empty())
		{
			cout<<XOX.top()<<' ';
			XOX.pop();
		}
		cout<<endl;
	}
	return 0;
}
