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
int tot=0;//下,右,上,左
vector<pii>vec;
bool ok=0;
pii rush(int ope,int to)
{
	int y=vec[ope].first,x=vec[ope].second;
	int dy=ny[to],dx=nx[to];
	while(y+dy<=h&&y+dy>=1&&x+dx<=w&&x+dx>=1&&s[y+dy][x+dx]!='X'&&s[y+dy][x+dx]!='R'&&s[y+dy][x+dx]!='?')
		y+=dy,x+=dx;
	return make_pair(y,x);
}
map<vector<pii>,bool>mp;
void show()
{
	for(int i=1;i<=h;i++)//y
	{
		for(int j=1;j<=w;j++)//x
			printf("%c",s[i][j]);
		printf("\n");
	}
	printf("\n");
}
void dfs(int tim)
{
//	printf("tim=%d,ope=%d,tot=%d\n",tim,ope,tot);
//	for(int i=0;i<tot;i++)
//		printf("R[%d,%d],",vec[i].first,vec[i].second);
//	printf("\n");
	if(tim==k+1)
	{
		for(int i=0;i<tot;i++)
		{
			for(int i=0;i<tot;i++)
			{
				pii &now=vec[i];
				if(s[now.first][now.second]=='D'||s[now.first][now.second]=='?')
					ok=1;
			}
			return;
		}
	}
	if(ok||tim>k)
		return;
//	show();
	for(int i=0;i<tot;i++)
	{//第tim秒,将i号车向j移动
		pii now=vec[i];
		for(int j=0;j<4;j++)
		{
			vec[i]=rush(i,j);
			s[now.first][now.second]='.';
			if(s[vec[i].first][vec[i].second]=='.')
				s[vec[i].first][vec[i].second]='R';
			else
				s[vec[i].first][vec[i].second]='?';
			dfs(tim+1);
			if(s[vec[i].first][vec[i].second]=='?')
				s[vec[i].first][vec[i].second]='D';//还原
			else
				s[vec[i].first][vec[i].second]='.';
			s[now.first][now.second]='R';
			vec[i]=now;
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
//				s[i][j]='.';
			}
		}
	dfs(1);
	cout<<(ok?"YES":"NO")<<endl;
	return 0;
}


