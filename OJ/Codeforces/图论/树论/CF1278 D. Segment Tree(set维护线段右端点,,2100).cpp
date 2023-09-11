//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
const int maxn=5e5+10,inf=0x3f3f3f3f,mod=1000000007;
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
int fa[maxn];
int findfa(int x)
{
	if(fa[x]!=x)
		fa[x]=findfa(fa[x]);
	return fa[x];
}
bool Merge(int x,int y)
{
	int a=findfa(x),b=findfa(y);
	if(a==b)
		return 0;
	if(a<b)
		fa[b]=a;
	else
		fa[a]=b;
	return 1;
}
struct node
{
	int ins,pos,id;
	node(int a,int b,int c):
		ins(a),pos(b),id(c){}
};
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
//	void TLE();
//	TLE();
	int n,l,r;
	vector<node>v;
	scanf("%d",&n);
//	cin>>n;
	int siz=n;
	vector<int> ms(2*n+2,0),ed(n+1,0);
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		scanf("%d%d",&l,&r);
//		cin>>l>>r;
		v.push_back(node(1,l,i));
		v.push_back(node(0,r,i));
		ms[l]=ms[r]=i;
		ed[i]=r;
	}
	sort(v.begin(),v.end(),[](const node &a,const node &b){
			return a.pos<b.pos;
		});
	bool ok=1;
	set<int>st;//维护终点
	set<int>::iterator it;
	for(auto &x:v)
	{//
		if(x.ins==1)//开始该线段左端点
		{
			for(it=st.begin();it!=st.end()&&*it<ed[x.id];it++)
			{//比这条线段早插入且早结束的,合并
				if(Merge(x.id,ms[*it]))
				{
					if(--siz<1)
						ok=0;
				}
				else//有环
					ok=0;
			}
			st.insert(ed[x.id]);//插入该线段右端点
		}
		else//删除右端点
			st.erase(x.pos);
		if(!ok)
			break;
	}
	printf("%s\n",(ok&&siz==1)?"YES":"NO");
//	cout<<(ok&&siz==1?"YES":"NO")<<endl;
	return 0;
}
/*
 *不难想到并查集...
 *但是想到了怎么O(n)check啊我滴妈
 *在长度数组上记录位置开set也复杂度爆炸啊
 *st不维护节点编号,而是维护当前存在线段右端点
 *怎么感觉好像一个复杂度...
 */
void TLE()
{
	int n,l,r;
	read(n);
//	vector<pii>v;
//	cin>>n;
	int siz=n;
	vector<int> ms(2*n+2,0),ed(n+1,0);
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		read(l,r);
//		cin>>l>>r;
		ms[l]=ms[r]=i;
		ed[i]=r;
//		v.push_back(pii(l,r));
	}
//	sort(v.begin(),v.end());
	bool ok=1;
	set<int>st;
//	set<int>::iterator it;
	for(int i=1;i<=2*n;i++)
		if(ms[i])
		{
			if(st.count(ms[i])==0)
			{//放入时与集合中存在且早于当前边结束的边连接
//				for(it=st.begin();it!=st.end();it++)
				for(auto &v:st)
				{
//					printf("%d,%d\n",ms[i],*it);
					if(ed[v]<ed[ms[i]])
					{
						if(Merge(ms[i],v))
						{
							siz--;
							if(siz<1)
								ok=0;
						}
						else
							ok=0;
					}
				}
				st.insert(ms[i]);
			}
			else//存在,则删除
				st.erase(ms[i]);
			if(!ok)
				break;
		}
	cout<<(ok&&siz==1?"YES":"NO")<<endl;
	exit(0);
}
