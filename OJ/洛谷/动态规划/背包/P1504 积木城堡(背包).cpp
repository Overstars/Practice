#include<bits/stdc++.h>
using namespace std;
const int maxn=1004;
vector<int> h;
int ans[100005];
bool jud[1000005];
int main()
{
//	freopen("P1504_1.in","r",stdin);
	int n,tem,maxn=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		h.clear();
		h.push_back(0);
		memset(jud,0,sizeof(jud));
		while(cin>>tem&&tem!=-1)
		{
			int siz=h.size();
			for(int j=0;j<siz;j++)
			{
				if(!jud[h[j]+tem])
				{
					h.push_back(h[j]+tem);
					jud[h[j]+tem]=1;
					maxn=max(maxn,h[j]+tem);
				}
			}
		}
		for(auto &a:h)
			ans[a]++;
	}
	for(int i=maxn;i>=0;i--)
		if(ans[i]==n)
		{
			cout<<i<<endl;
			break;
		}
	return 0;
}
