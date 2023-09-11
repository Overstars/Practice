#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int a[maxn],b[maxn];
int main()
{
	int n,s;
	cin>>n>>s;
	for(int i=1;i<=n;i++)
		cin>>a[i];//1->n
	for(int i=1;i<=n;i++)
		cin>>b[i];//n->1
	if(!a[1]||(a[s]==0&&b[s]==0))
		cout<<"NO\n";
	else if(a[s]==1)
	{
		cout<<"YES\n";
	}
	else{
		for(int i=n;i>=1;i--)
		{
			if(a[i]==1&&b[i]==1)
			{
				if(i>=s)
				{
					cout<<"YES\n";
					exit(0);
				}
			}
		}
		cout<<"NO\n";
	}
	return 0;
}
