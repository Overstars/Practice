#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
char s[maxn];
int a[maxn],b[maxn];
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=2;i<=n;i++)
	{
		if(s[i]=='B'&&s[i-1]=='A')
			a[i]=1;
		if(s[i]=='A'&&s[i-1]=='B')
			b[i]=1;
	}
//	for(int i=1;i<=n;i++)
//		printf("%d,%d\n",a[i],b[i]);
	for(int i=2;i<=n;i++)
	{
		if(a[i])
		{
			for(int j=2;j<=i-2;j++)
			{
				if(b[j])
				{
					printf("YES\n");
					exit(0);
				}
			}
			for(int j=i+2;j<=n;j++)
			{
				if(b[j])
				{
					printf("YES\n");
					exit(0);
				}
			}
		}
	}
	puts("NO");
	return 0;
}
