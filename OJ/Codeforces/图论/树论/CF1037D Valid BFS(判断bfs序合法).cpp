//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;
const double eps=1e-9;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
vector<int>G[maxn];
int a[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,u,v;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	bool ok=1;
	if(a[1]!=1)
		ok=0;
	set<int>st;
	queue<int>QAQ;
	vector<bool>vis(n+1,false);
	QAQ.push(a[1]);
	vis[1]=1;
	int ind=2;
	while(!QAQ.empty())
	{
		int x=QAQ.front();
		QAQ.pop();
		vis[x]=1;
		for(int &v:G[x])//x的下一轮
			if(!vis[v])//x的子节点
				st.insert(v);
		int siz=st.size();
		for(int i=0;i<siz;i++)
		{
			if(st.count(a[ind+i])==0)
			{
				ok=0;
				break;
			}
			else{
				st.erase(a[ind+i]);
				QAQ.push(a[ind+i]);
			}
		}
		ind+=siz;//跳过这些子节点
		if(!ok)
			break;
	}
	cout<<(ok?"Yes":"No")<<endl;
	return 0;
}


