#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int k[maxn];
int main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,m;
	cin>>t;
	while(t--)
	{
		cin>>m;//最终合成出来30
		vector<int>st[32],ans;
		for(int i=1;i<=m;i++)
		{
			cin>>k[i];
			st[k[i]].push_back(i);
		}
		bool flag=0;
		for(ll i=29,need=2;i>=0;i--,need<<=1)
		{
			if(st[i].size()>=need)
			{
				flag=1;
				for(int j=0;j<need;j++)
				{
					ans.push_back(st[i][j]);
				}
				break;
			}
			else{
				ans.insert(ans.end(),st[i].begin(),st[i].end());
				need-=st[i].size();
			}
		}
		if(!flag)
			cout<<"impossible"<<endl;
		else{
			sort(ans.begin(),ans.end());
			for(int i=1;i<=m;i++)
			{
				if(lower_bound(ans.begin(),ans.end(),i)!=ans.end()&&*lower_bound(ans.begin(),ans.end(),i)==i)
					cout<<1;
				else
					cout<<0;
			}
			cout<<endl;
		}
	}
	return 0;
}


