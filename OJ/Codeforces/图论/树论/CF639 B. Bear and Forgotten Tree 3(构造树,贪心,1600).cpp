#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f,mod=1000000007;
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
//#define DEBUG//<<setiosflags(ios::fixed)<<setprecision(9)
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,d,h;
	cin>>n>>d>>h;//最长链d,深度h
	if(n<h||n<d||d>2*h||(d==1&&n>2))
	{
		cout<<"-1\n";
		exit(0);
	}
	for(int i=1,j=2;j<=h+1;i=j,j++)//先来一个深度,h+1
	{
		cout<<i<<' '<<j<<endl;
	}//长度还剩d-h
	for(int i=1,j=h+2,c=0;j<=d+1;i=j,j++)//最长链,1,h+2~
		cout<<i<<' '<<j<<endl;
	for(int j=d+2;j<=n;j++)
	{
		if(h<d)
			cout<<1<<' '<<j<<endl;
		else if(h>=2)
			cout<<2<<' '<<j<<endl;
	}
	return 0;
}


