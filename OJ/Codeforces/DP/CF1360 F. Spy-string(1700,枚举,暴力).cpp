//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
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
bool check(string &s,vector<string> &rec)
{
	int n=s.length();
	for(string &t:rec)
	{
		int cnt=0;
		for(int i=0;i<n;i++)
			if(s[i]!=t[i])
				cnt++;
		if(cnt>1)
			return 0;
	}
	return 1;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n,m;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
//		vector<vector<int>> cnt(26,vector<int>(m,0));
		vector<string> rec;
		for(int i=1;i<=n;i++)
		{
			cin>>s;
			rec.push_back(s);
//			for(int i=0;i<m;i++)
//				cnt[s[i]-'a'][i]++;
		}
		string ans=rec[0];//修改此上的一个字符
		bool ok=0;
		for(int i=0;i<m;i++)
		{
//			bool flag=0;
			char now=ans[i];
			for(char ch='a';ch<='z';ch++)
			{
				ans[i]=ch;
				if(check(ans,rec))
				{
//					cout<<ans<<endl;
					ok=1;
					break;
				}
			}
			if(ok)
				break;
			ans[i]=now;
		}
		if(ok)
			cout<<ans<<endl;
		else
			cout<<-1<<endl;
	}
	return 0;
}
/*
 *构造一个串要求和n个串每个不同字母数不超过1
*/

