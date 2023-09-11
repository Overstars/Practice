#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=55,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
struct node
{
	int x,y,siz;
};
int cnt=0,val=0,n,m,k,nx[4]={0,1,0,-1},ny[4]={1,0,-1,0};
char mp[maxn][maxn];
int vis[maxn][maxn];
vector<node>rec;
bool bfs(int x,int y)
{
	queue<node>QAQ;
	node now,nex;
	now.x=x,now.y=y;
	bool bor=0;
	int siz=0;
	vis[x][y]=++cnt;
	QAQ.push(now);
	while(!QAQ.empty())
	{
		now=QAQ.front();
		siz++;
		QAQ.pop();
		for(int i=0;i<4;i++)
		{
			nex.x=now.x+nx[i];
			nex.y=now.y+ny[i];
			if(nex.x<1||nex.x>n||nex.y<1||nex.y>m)//边界
			{
				bor=1;
				continue;
			}
			if(vis[nex.x][nex.y]>0||mp[nex.x][nex.y]=='*')
				continue;
			vis[nex.x][nex.y]=cnt;
			QAQ.push(nex);
		}
	}
	now.x=x,now.y=y,now.siz=siz;
	if(!bor)
	{
		val++;
		rec.push_back(now);
	}
	if(val<=k||bor)
		return 0;
	return 1;
}
bool cmp(const node &a,const node &b)
{
	return a.siz<b.siz;
}
int del(int num)
{
	sort(rec.begin(),rec.end(),cmp);
	queue<node> QAQ;
	node now,nex;
	int ret=0;
	for(int i=0;i<num;i++)
	{
		ret+=rec[i].siz;
		now.x=rec[i].x,now.y=rec[i].y;
		QAQ.push(now);
		while(!QAQ.empty())
		{
			now=QAQ.front();
//			printf("(%d,%d)\n",now.x,now.y);
			QAQ.pop();
			mp[now.x][now.y]='*';
			for(int j=0;j<4;j++)
			{
				nex.x=now.x+nx[j];
				nex.y=now.y+ny[j];
				if(nex.x<1||nex.x>n||nex.y<1||nex.y>m)//不会越界的...
					continue;
				if(vis[nex.x][nex.y]==vis[rec[i].x][rec[i].y]&&mp[nex.x][nex.y]=='.')
				{
//					printf("???\n");
					QAQ.push(nex);
				}
			}
		}
	}
	return ret;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>mp[i]+1;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]=='.'&&!vis[i][j])
				bfs(i,j);
		}
	}
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=m;j++)
//			cout<<vis[i][j]<<(j==m?'\n':' ');
	cout<<del(val-k)<<endl;
	for(int i=1;i<=n;i++)
		cout<<mp[i]+1<<endl;
	return 0;
}


