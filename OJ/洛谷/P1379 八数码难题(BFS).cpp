//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
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
int bfs(string s)
{
	unordered_map<string,int>vis;
	queue<string>q;
	string target="123804765";
	int nx[]={0,1,0,-1},ny[]={1,0,-1,0};
	vis[s]=0;
	q.push(s);
	while(!q.empty())
	{
		string now=q.front();
		q.pop();
		if(now==target)
			return vis[now];
		int pos=now.find('0'),d=vis[now];
		int x=pos/3,y=pos%3;
		for(int i=0;i<4;i++)
		{
			int xx=x+nx[i],yy=y+ny[i];//0移动到的位置
			if(xx<0||xx>2||yy<0||yy>2)
				continue;
			swap(now[xx*3+yy],now[pos]);
			if(vis.count(now)==0)
			{
				vis[now]=d+1;
				q.push(now);
			}
			swap(now[xx*3+yy],now[pos]);
		}
	}
	return inf;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	string s;
	cin>>s;
	cout<<bfs(s)<<endl;
	return 0;
}


