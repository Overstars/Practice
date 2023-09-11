#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>//¿ØÖÆÊä³ö,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
const int inf=0x3f3f3f3f;
int main()
{
	int t,n,m,a,b;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int c=0;
		while(cin>>n>>m&&(n||m))
		{
			int cnt=0;
			for(int a=1;a<n;a++)
				for(int b=a+1;b<n;b++)
					if((a*a+b*b+m)%(a*b)==0)
						cnt++;
			printf("Case %d: %d\n",++c,cnt);
		}
		if(i<t)
			putchar('\n');
	}
	return 0;
}
