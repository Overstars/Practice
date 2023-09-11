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
struct ope
{
	int l,r,g;
	ope(int l,int r,int g):
		l(l),r(r),g(g){}
};
vector<int>des,be[maxn],ed[maxn];
int res[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	map<int,int>mp;
	vector<ope>op;
	int n,m,l,r,d,cnt=0;
	cin>>n>>m;
	while(m--)
	{
		cin>>l>>r>>d;//[l,r]存入货物d
		op.push_back(ope(l,r,d));
		des.push_back(d);
	}
	sort(des.begin(),des.end());//对货物去重
	des.erase(unique(des.begin(),des.end()),des.end());
	for(auto &i:op)
	{
		i.g=lower_bound(des.begin(),des.end(),i.g)-des.begin()+1;
		be[i.l].push_back(i.g);
		ed[i.r].push_back(i.g);
	}
	int ans=0,num=0,now=0;
	for(int i=1;i<=n;i++)
	{//now维护i的货物种类数
		for(int j:be[i])//[i,?]范围的货物j
		{
			if(!res[j])//该区域初次被j覆盖
				now++;
			res[j]++;//res是一个差分数组
		}
		if(now>ans)
		{
			ans=now;
			num=i;//种类最多的货舱
		}
		for(int j:ed[i])//[?,i]范围的货物
		{
			res[j]--;
			if(!res[j])//该区域不再被j覆盖
				now--;
		}
	}
	cout<<num<<endl;
	return 0;
}


