//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
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
int y[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>y[i];
	bool ok=0;
	for(int i=2;i<=n;i++)//y[i]-y[1]|(i-1)
	{
//		if((y[i]-y[1])%(i-1))
//			continue;
		int k=y[i]-y[1],g=max(i-1,1ll);
		vector<int>have,oth;
		have.push_back(1);
		if(i!=1)
			have.push_back(i);
		for(int j=2;j<=n;j++)
		{//y[j]=y[1]+k*(j-1)
			if(j==i)
				continue;
			if(k*(j-1)%g)//不是整数
			{
				oth.push_back(j);
				continue;
			}
			else if(y[j]!=y[1]+k*(j-1)/g)//不在一条线上
				oth.push_back(j);
			else
				have.push_back(j);
		}
//		printf("now = %d/%d\n",k,g);
//		for(auto &j:oth)
//			cout<<j<<endl;
		bool flag=1;
		if(oth.size()==1)
		{
			ok=1;
			break;
		}
		if(oth.empty())
			continue;
		int st=oth[0];
		for(int &j:oth)
		{
			if((j-st)*k!=g*(y[j]-y[st]))
			{
//				printf("%d!=%d\n",st,j);
				flag=0;
			}
		}
		if(flag)
		{
			ok=1;
			break;
		}
	}
	bool flag=1;
	int k=y[3]-y[2];
	for(int i=4;i<=n;i++)
		if(y[i]!=y[2]+k*(i-2))
			flag=0;
	if(y[1]==y[2]-k)
		flag=0;
	ok|=flag;
	cout<<(ok?"Yes":"No")<<endl;
	return 0;
}
/*
 * 2021-05-02-15.16.25
*/

