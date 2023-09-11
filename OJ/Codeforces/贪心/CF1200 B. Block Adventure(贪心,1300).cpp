#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=105;
int h[maxn];
int main()
{
	int t,n,m,k;//n列,初始m块砖,lim=k
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k;
		for(int i=1;i<=n;i++)
			cin>>h[i];
		int i;
		for(i=1;i<n;i++)
		{
			if(h[i]+m+k<h[i+1])//到不了下一个
				break;
			if(h[i]+k<h[i+1])//放砖
				m-=h[i+1]-h[i]-k;
			else//拿砖
			{
				int tak=h[i]+k-h[i+1];
				h[i]-=tak;
				if(h[i]<0)
					tak+=h[i];
				m+=tak;
			}
//			printf("h[%d]=%d,m=%d\n",i,h[i],m);
		}
		if(i==n)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}
