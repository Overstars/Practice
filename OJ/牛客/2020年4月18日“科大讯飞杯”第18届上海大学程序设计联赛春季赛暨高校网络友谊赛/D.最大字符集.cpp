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
char s[maxn];
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n;
	cin>>n;
	if(n==1)
	{
		cout<<1<<endl;
		cout<<1<<endl;
		return 0;
	}
	if(n==2)
	{
		cout<<2<<endl;
		cout<<"1"<<endl;
		cout<<"00"<<endl;
		return 0;
	}
	cout<<n-1<<endl;
	for(int i=0;i<=n-2;i++)
	{
		cout<<"0";
		for(int j=0;j<i;j++)
		{
			cout<<"1";
		}
		cout<<"0"<<endl;
	}
	return 0;
}


