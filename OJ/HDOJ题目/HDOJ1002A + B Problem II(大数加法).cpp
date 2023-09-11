#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<map>
using namespace std;
#define PI 3.14159265358979323846
#define e  2.7182818284590452354
#define ln_2 0.69314718055994530942
#define ln_10 2.30258509299404568402
const int inf=0x3f3f3f3f;
char s1[1005],s2[1005],ans[1010];
char t1[1005],t2[1005];
int len;
void resever(char *t,char *ret,int l)
{
	for(int i=l-1,z=0;i>=0;i--)
		ret[z++]=t[i]-'0';
}
void BigNumAdd(char *a,char *b)
{
//	memset(ans,0,sizeof(ans));
	memset(s1,0,sizeof(s1));//放到resver里就WA...
	memset(s2,0,sizeof(s2));
	int alen=strlen(t1),blen=strlen(t2),cc=0;
	resever(t1,a,alen);
	resever(t2,b,blen);
	len=max(alen,blen);
	for(int i=0;i<len;i++)
	{
		ans[i]=a[i]+b[i]+cc;
		cc=ans[i]/10;
		ans[i]%=10;
	}
	if(cc)
	{
		ans[len]=cc;
		len++;
	}
}
void show(char *st,int l)
{
	for(int i=l-1;i>=0;i--)
		putchar(st[i]+'0');
	putchar('\n');
}
int main()
{
	int t,i;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		memset(t1,0,sizeof(t1));
		memset(t2,0,sizeof(t2));
		scanf("%s %s",t1,t2);
		if(i>1)
			putchar('\n');
		printf("Case %d:\n",i);
		printf("%s + %s = ",t1,t2);
		BigNumAdd(s1,s2);
		show(ans,len);
	}
	return 0;
}
