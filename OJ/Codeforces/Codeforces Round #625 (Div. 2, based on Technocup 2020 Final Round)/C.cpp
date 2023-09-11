#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	stack<char>stk;
	char ch;
	int n;
	string s;
	while(cin>>n>>s)
	{
		int ans=0;
		while(1)
		{
			bool flag=0,tar=0;
			string tmp;
			for(int i=0;i<s.length();i++)
			{
				if(i==0&&s.length()>1)
				{
					if(s[i]==s[i+1]+1)
					{
						flag=1;
//						break;
					}
				}
				else if(s.length()>1&&i==s.length()-1)
				{
					if(s[i]==s[i-1]+1)
					{
						flag=1;
//						break;
					}
				}
				else if(i>=1&&i<s.length()-1)
				{
					if(s[i]==s[i+1]+1||s[i]==s[i-1]+1)
					{
						flag=1;
//						break;
					}
				}
				if(flag)
				{
					s.erase(i,1);
					break;
				}
			}
			if(!flag)
				break;
		}
//		cout<<ans<<endl;
		cout<<n-s.length()<<endl;
	}
	return 0;
}


