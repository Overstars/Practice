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
	int t,n,k,cnt=0;
	map<char,int>mp;
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>s+1;
		sort(s+1,s+n+1);
		if(s[1]!=s[k])
			cout<<s[k]<<endl;
		else if(s[n]==s[k+1])
		{//剩下的n-k个字符一样,平均分配
			cout<<s[k];
            int len=(n-k)/k+((n-k)%k?1:0);
            for(int i=1;i<=len;i++)
				cout<<s[k+1];
			cout<<endl;
		}
		else//不一样,都接到同一个后面
			cout<<s[1]<<s+k+1<<endl;
	}
	return 0;
}


