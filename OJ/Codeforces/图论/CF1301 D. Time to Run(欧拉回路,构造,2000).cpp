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
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll n,m,k;
	#define pis pair<int,string>
	vector<pis>rec;
	cin>>n>>m>>k;
	if(k>4*n*m-2*n-2*m)
		return cout<<"NO"<<endl,0;
	if(m>1)//向右到头
	{
		rec.push_back(pis(min(m-1,k),"R"));
		k-=m-1;//减哪个都行,反正小于零就输出
		if(k<=0)
			goto label;
	}
	if(n>1)//向下到头
	{
		rec.push_back(pis(min(n-1,k),"D"));
		k-=n-1;
		if(k<=0)
			goto label;
	}
	if(m>1)//向左到头
	{
		rec.push_back(pis(min(m-1,k),"L"));
		k-=m-1;
		if(k<=0)
			goto label;
	}
	if(n>1)//向上到头
	{
		rec.push_back(pis(min(n-1,k),"U"));
		k-=n-1;
		if(k<=0)
			goto label;
	}
	if(n>1)//向下到头
	{
		rec.push_back(pis(min(n-1,k),"D"));
		k-=n-1;
		if(k<=0)
			goto label;
	}
	if(m>1)//向右到头
	{
		rec.push_back(pis(min(m-1,k),"R"));
		k-=m-1;
		if(k<=0)
			goto label;
	}
	for(int i=1;i<=n-2;i++)
	{//U,L*(m-1),R*(m-1)循环
		if(k--<=0)
			goto label;
		rec.push_back(pis(1,"U"));
		if(k<=0)
			goto label;
		rec.push_back(pis(min(m-1,k),"L"));
		k-=min(m-1,k);
		if(k<=0)
			goto label;
		rec.push_back(pis(min(m-1,k),"R"));
		k-=min(m-1,k);
		if(k<=0)
			goto label;
	}
	if(k-->0)//补最后一个向上,回到第一行
		rec.push_back(pis(1,"U"));
	for(int i=1;i<=m-2;i++)
	{//L,D*(n-1),U*(n-1)循环
		if(k--<=0)
			goto label;
		rec.push_back(pis(1,"L"));
		if(k<=0)
			goto label;
		rec.push_back(pis(min(n-1,k),"D"));
		k-=min(n-1,k);
		if(k<=0)
			goto label;
		rec.push_back(pis(min(n-1,k),"U"));
		k-=min(n-1,k);
		if(k<=0)
			goto label;
	}
	if(k-->0)//补最后一个向左,回到起点
		rec.push_back(pis(1,"L"));
	label:
	cout<<"YES"<<'\n'<<rec.size()<<endl;
	for(pis &x:rec)
		cout<<x.ff<<' '<<x.ss<<endl;
	return 0;
}
/*
3 4 16
*/
/*
 *2020年9月3日17点36分
 *2020年9月3日21点08分
 *
 *因为所有格子入度=出度,所以该图必定具有欧拉回路
 *根据度数来看,角落格子访问两次,边三次,中间四次
*/
