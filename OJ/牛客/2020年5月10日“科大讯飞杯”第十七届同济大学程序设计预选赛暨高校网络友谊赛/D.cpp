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
char s[15][15];
int w,h,k,nx[]={0,1,0,-1},ny[]={1,0,-1,0};//宽度,高度
int tot=0;
vector<pii>vec;
bool ok=0;
bool check(int y,int x)
{//x横y竖
	if(x<1||y<1||x>w||y>h||s[y][x]=='X')
		return 0;
	for(auto &i:vec)
		if(y==i.first&&x==i.second)
			return 0;
	return 1;
}
map<vector<pii>,bool>mp;
void dfs(int tim,int ope)
{
//	printf("tim=%d,ope=%d,tot=%d\n",tim,ope,tot);
//	for(int i=0;i<tot;i++)
//		printf("R[%d,%d],",vec[i].first,vec[i].second);
//	printf("\n");
	if(ok||tim>k||ope>=tot)
		return;
	pii &now=vec[ope];
	int y=now.first,x=now.second;
	for(int i=0;i<4;i++)
	{
		int yy=y+ny[i],xx=x+nx[i];
		if(check(yy,xx)&&tim<=k)
		{
			if(s[yy][xx]=='D'&&tim<=k)
				ok=1;
			now.first=yy,now.second=xx;
			if(mp.find(vec)!=mp.end())
				mp[vec]=1;
			for(int j=0;j<tot;j++)
				dfs(tim+1,j);
			now.first=y,now.second=x;
		}
	}
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	cin>>w>>h>>k;
	for(int i=1;i<=h;i++)
		cin>>s[i]+1;
	for(int i=1;i<=h;i++)//y
		for(int j=1;j<=w;j++)//x
		{
			if(s[i][j]=='R')
			{
				tot++;
				vec.push_back(make_pair(i,j));
				s[i][j]='.';
			}
		}
	for(int i=0;i<tot;i++)
		dfs(1,i);
	cout<<(ok?"YES":"NO")<<endl;
	return 0;
}


