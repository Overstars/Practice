#include<bits/stdc++.h>
using namespace std;
char ans[1005];
int main()
{
	int m,s;
	cin>>m>>s;
	if(s<1&&m>1||s>m*9)
		cout<<"-1 -1\n";
	else{
		for(int ret=s,i=m;i>=1;i--)
		{
			if(ret>0)
			{
				ans[i]='0'+min(ret,9);
				ret-=min(ret,9);
			}
			else
				ans[i]='0';
		}
		if(ans[1]=='0')
		{
			for(int i=1;i<=m;i++)
			{
				if(ans[i]>'0')
				{
					ans[i]--;
					ans[1]++;
					break;
				}
			}
		}
		cout<<ans+1<<' ';
		for(int ret=s,i=1;i<=m;i++)
		{
			if(ret>0)
			{
				ans[i]='0'+min(ret,9);
				ret-=min(s,9);
			}
			else
				ans[i]='0';
		}
		cout<<ans+1<<endl;
	}
	return 0;
}
