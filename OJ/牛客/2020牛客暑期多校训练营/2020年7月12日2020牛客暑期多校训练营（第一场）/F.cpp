//#pragma comment(linker, "/STACK:102400000,102400000")
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
void show(int flag,bool tra)
{
	if((flag==1&&!tra)||(flag==2&&tra))
		cout<<"<"<<endl;
	else if((flag==2&&!tra)||(flag==1&&tra))
		cout<<">"<<endl;
	else
		cout<<"="<<endl;
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	string a,b;
	while(cin>>a)
	{
		cin>>b;
		int ok=0;//1小,2大,3等
		bool tra=0;
		int n=a.length(),m=b.length();
		int lim=min(n,m);
		if(n>m)
		{
			tra=1;
			swap(n,m);
			swap(a,b);
		}
		b+=b;
		m<<=1;
//		cout<<b<<endl;
		for(int i=0;i<m;i++)
		{
			if(a[i%n]<b[i])
			{
				ok=1;
				break;
			}
			else if(a[i%n]>b[i])
			{
				ok=2;
				break;
			}
		}
		show(ok,tra);
	}
	return 0;
}


