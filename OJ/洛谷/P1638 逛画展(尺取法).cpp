#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
int a[maxn],cnt[2005];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ansl=1,ansr=1,rec=0x3f3f3f3f;
	for(int l=1,r=1,tot=0;l<=n;)
	{
		while(tot<m&&r<=n)
		{
			if(!cnt[a[r]])
				tot++;
			cnt[a[r++]]++;
		}
		if(tot==m)
		{
			if(r-l<rec)
			{
				ansl=l;
				ansr=r-1;
				rec=r-l;
			}
		}
		else
			break;
		if(--cnt[a[l++]]==0)
			tot--;
	}
	cout<<ansl<<' '<<ansr<<endl;
	return 0;
}
