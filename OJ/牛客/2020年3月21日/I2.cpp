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
	string s,rec,ans;
	while(cin>>s)
	{
//		cin>>s;
		ans=s;
		vector<int>st[30];
		for(int i=0;i<s.length();i++)
			st[s[i]-'a'].push_back(i);
		for(int i=25;i>=0;i--)
		{
			if(st[i].empty())
				continue;
			for(auto &j:st[i])//该字母起始位置
			{
				bool flag=0;
				for(int k=0;k<ans.length()&&j+k<s.length();k++)
				{
					if(s[j+k]>ans[k])
					{
						flag=1;
//						printf("!!!\n");
						break;
					}
					else if(s[j+k]<ans[k])
					{
						flag=0;
						break;
					}
				}
//	cout<<i<<",j="<<j<<",ans="<<ans<<endl;
				if(flag)
					ans=s.substr(j);
			}
			if(!ans.empty())
				break;
		}
		cout<<ans<<endl;
	}
	return 0;
}


