#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+5,inf=0x3f3f3f3f,mod=1000000007;
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
//#define DEBUG//<<setiosflags(ios::fixed)<<setprecision(9)
struct node
{
	int no;
	ll a,b;
} the[maxn];
bool cmp(const node &x,const node &y)
{
	return x.a+x.b>y.a+y.b;
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
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		the[i].no=i;
		cin>>the[i].a;
	}
	for(int i=1;i<=n;i++)
		cin>>the[i].b;
	sort(the+1,the+1+n,cmp);
	vector<int> h,t;//牛牛,可乐
	for(int i=1;i<=n;i++)
	{
		if(i&1)
			h.push_back(the[i].no);
		else
			t.push_back(the[i].no);
	}
	for(auto &i:h)
		cout<<i<<' ';
	cout<<endl;
	for(auto &i:t)
		cout<<i<<' ';
	return 0;
}


