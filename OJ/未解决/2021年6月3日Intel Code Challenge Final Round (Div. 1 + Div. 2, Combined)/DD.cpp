//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
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
char s[maxn];
int pre[maxn],nex[maxn];
struct node
{
	char ch;
	int pos;
	node(char c='a',int p=0):
		ch(c),pos(p){}
	bool operator <(const node &c)const{
		return ch<c.ch;
	}
};
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int m;
	cin>>m>>s+1;
	int n=strlen(s+1);
	priority_queue<node>pq;
	map<char,int>cnt;
	for(int i=1;i<=n;i++)
	{
		pre[i]=i-1;
		nex[i]=i+1;
		pq.push(node(s[i],i));
		cnt[s[i]]++;
//		if(i==1)
//			pre[i]=-inf;
//		if(i==n)
//			nex[i]=inf;
	}
	char pc='z';
	bool flag=0;
	while(!pq.empty())
	{
		node now=pq.top();
		pq.pop();
		if(flag&&now.ch!=pc)
			break;
		if(nex[now.pos]-pre[now.pos]-1>=(m))
		{
			flag=1;
			pc=now.ch;
		}
		else{
			cnt[now.ch]--;
			nex[pre[now.pos]]=nex[now.pos];//上一个点的下
			pre[nex[now.pos]]=pre[now.pos];
		}
	}
	for(char ch='a';ch<='z';ch++)
	{
		int num=cnt[ch];
		for(int i=1;i<=num;i++)
			cout<<ch;
	}
	cout<<endl;
	return 0;
}
/*
 * 2021-06-04-00.03.07
 * C:\Users\dell\Desktop\2021年6月3日Intel Code Challenge Final Round (Div. 1 + Div. 2, Combined)\DD.cpp
 *
*/

