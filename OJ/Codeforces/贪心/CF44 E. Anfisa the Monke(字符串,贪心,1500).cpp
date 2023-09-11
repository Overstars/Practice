#include<bits/stdc++.h>
using namespace std;
const int maxn=205;//
int dp[maxn];//
char s[maxn];
int main()
{
	int k,a,b,n;
	cin>>k>>a>>b>>s+1;
	n=strlen(s+1);//将n分成k块且
	if(k*min(a,b)>n||k*max(a,b)<n)
		cout<<"No solution\n";
	else{
		int len=n/k;
		for(int i=1,res=n-k*(len);i<=n;)
		{
			if(res>0)
			{
				int cnt=0;
				while(cnt<len+1&&i+cnt<=n)
				{
					putchar(s[i+cnt]);
					cnt++;
				}
				i+=cnt;
				res--;
			}
			else{
				int cnt=0;
				while(cnt<len&&i+cnt<=n)
				{
					putchar(s[i+cnt]);
					cnt++;
				}
				i+=cnt;
			}
			printf("\n");
		}
	}
	return 0;
}
