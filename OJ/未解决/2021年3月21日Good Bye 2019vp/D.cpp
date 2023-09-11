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
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,k,pos,val,mx=0;
	cin>>n>>k;
	map<int,int>mp;
	for(int i=1;i<=k+1;i++)
	{
		cout<<"?";
		for(int j=1;j<=k+1;j++)
		{
			if(j==i)
				continue;
			cout<<" "<<j;
		}
		cout<<endl;
		cout.flush();
		cin>>pos>>val;
		mx=max(mx,val);
		mp[val]++;
	}
	cout<<"! "<<mp[mx]<<endl;
	return 0;
}
/*
 * n个不同数字,找到m
 * 一次可以询问k个
 * 你得到询问这k个之间的第m大的元素的值和位置
 * 你并不知道m是多少,请确定m
 * 枚举询问[1,k+1]区间内删掉一个元素
 * 统计一下每个值的数量
*/

