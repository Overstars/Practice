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
char d[6];
int x,y;
map<char,int>mp,cnt;
//inline int id(char ch)
//{
//
//}
bool equ(int nx,int ny)
{
	return (nx==x)&&(ny==y);
}
bool check(string &s)
{
	int nx=0,ny=0;
	bool ok=1;
	if(equ(nx,ny))
		ok=0;
	for(char &ch:s)
	{
		if(ch=='U')
			ny++;
		else if(ch=='D')
			ny--;
		else if(ch=='L')
			nx--;
		else
			nx++;
		if(equ(nx,ny))
			ok=0;
	}
	return ok;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>x>>y>>s;
		cnt.clear();
		for(auto &ch:s)
			cnt[ch]++;
		bool ok=0;
		string ans;
		d[1]='D';d[2]='L',d[3]='R',d[4]='U';
		do{
			ans.clear();
			for(int i=1;i<=4;i++)
				mp[d[i]]=i;
			for(int i=1;i<=4;i++)
				ans.insert(ans.length(),cnt[d[i]],d[i]);
			if(check(ans))
			{
				ok=1;
				break;
			}
		}while(next_permutation(d+1,d+5));
		if(ok)
			cout<<ans<<endl;
		else
			cout<<"Impossible"<<endl;
	}
	return 0;
}
/*
 * 2021-06-04-17.45.46
 * C:\Users\dell\Desktop\2021年6月4日2020-2021 ACM-ICPC, Asia Nanjing Regional Contest (XXI Open Cup, Grand Prix of Nanjing)\EE.cpp
 *
*/

