#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int d[500],ok=0,n;
multiset<int>ans;
map<int,int>mp;
void dfs(int pos,int k)//尝试将pos位作为右端第k个点
{//d[pos]作为下标(到0距离)
	if(k==n)
	{
		for(auto &i:ans)
			cout<<i<<' ';
	}
	if(ok||k<0||k>=n||pos<1)
		return;
	int v=d[pos];
	map<int,int>tmp;//存储所有已知点到该点距离
	for(auto &u:ans)
		tmp[abs(u-v)]++;
	bool flag=1;
	for(map<int,int>::iterator it=tmp.begin();it!=tmp.end();it++)
	{
		if(mp[it->first]<it->second)
		{
			flag=0;
			break;
		}
	}
	if(flag)//可以的
	{
//		printf("???\n");
		ans.insert(v);
//		for(auto &i:ans)
//			cout<<i<<' ';
//		printf("!!!\n");
		for(map<int,int>::iterator it=tmp.begin();it!=tmp.end();it++)
			mp[it->first]-=it->second;
		dfs(pos-1,k+1);
		for(map<int,int>::iterator it=tmp.begin();it!=tmp.end();it++)
			mp[it->first]+=it->second;
		ans.erase(v);
	}
	else
		dfs(pos-1,k);
}
signed main()
{
//	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		mp.clear();
		ans.clear();
		ans.insert(0);
		for(int i=1;i<=n*(n-1)/2;i++)
			cin>>d[i],mp[d[i]]++;//所有点对的距离
		sort(d+1,d+n*(n-1)/2+1);
		dfs(n*(n-1)/2,1);
//		sort(ans.begin(),ans.end());
		cout<<endl;
	}
	return 0;
}


