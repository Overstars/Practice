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
bool jud(int a,int b,int c)
{
	if(a+b<=c||b+c<=a||a+c<=b)
		return 0;
	return 1;
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
	int a,b,c;
	cin>>a>>b>>c;
	if(!jud(a,b,c))
	{
		cout<<"wtnl"<<endl;
		exit(0);
	}
	double x=(double)(a+c-b)/2,y=(double)(a+b-c)/2,z=(double)(b+c-a)/2;
	if(x<=0||y<=0||z<=0)
		cout<<"No"<<endl;
	else{
		cout<<"Yes"<<endl;
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<x<<' '<<y<<' '<<z<<endl;
	}
	return 0;
}


