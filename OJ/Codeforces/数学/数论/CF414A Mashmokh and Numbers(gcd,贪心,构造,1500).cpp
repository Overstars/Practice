#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
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
	ll n,k;
	cin>>n>>k;
	if(k<n/2||(n==1&&k>0))
		cout<<-1<<endl;
	else{
		ll tot=n/2,res=0,g=0;//g对得分
		if(n==1)
		{
			cout<<1<<endl;
			exit(0);
		}
		g=k/tot;
		if(k%tot==0)//k=tot
		{
			for(int i=1;i<=n;i++)
				cout<<i*g<<' ';
			exit(0);
		}
		else{//tot大于1,贡献tot-1,剩k-(tot-1)
			cout<<k-(tot-1)<<' '<<2*(k-tot+1)<<' ';
			for(int i=2*(k-tot+1)+1,j=3;j<=n;i++,j++)
				cout<<i<<' ';
		}
	}
	return 0;
}


