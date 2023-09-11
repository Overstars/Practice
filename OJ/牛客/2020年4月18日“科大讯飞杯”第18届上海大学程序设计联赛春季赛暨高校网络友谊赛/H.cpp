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
int cnt[10];
char s[maxn];
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,k,n;
	cin>>t;
	while(t--)
	{
		cin>>s+1>>k;
		n=strlen(s+1);
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++)
			cnt[s[i]-'0']++;
		string ans;
		for(int i=9;i>=0;i--)
		{
			if(i%3==0)
			{//0,3,6,9直接取
				while(ans.length()<k&&cnt[i]>0)
				{
					ans+='0'+i;
					cnt[i]--;
				}
			}
			else if(i%3==1)
			{//与2,5,8互补
				string tmp;
				int now=0;
				while(ans.length()+now<=k-2&&cnt[i]>0)
				{
					bool ok=1;
					if(cnt[8]>0)
					{
						tmp+='8';
						cnt[8]--;
					}
					else if(cnt[5]>0)
					{
						tmp+='5';
						cnt[5]--;
					}
					else if(cnt[2]>0)
					{
						tmp+='2';
						cnt[2]--;
					}
					else
						ok=0;
					if(ok)
						ans=ans+(char)('0'+i),cnt[i]--,now++;
					else
						break;
				}
				ans=ans+tmp;
			}
			else{//1,4,7
				string tmp;
				int now=0;
				while(ans.length()+now<=k-2&&cnt[i]>0)
				{
					bool ok=1;
					if(cnt[7]>0)
					{
						tmp+='7';
						cnt[7]--;
					}
					else if(cnt[4]>0)
					{
						tmp+='4';
						cnt[4]--;
					}
					else if(cnt[1]>0)
					{
						tmp+='1';
						cnt[1]--;
					}
					else
						ok=0;
					if(ok)
						ans=ans+(char)('0'+i),cnt[i]--,now++;
					else
						break;
				}
				ans=ans+tmp;
			}
//			cout<<"ans="<<ans<<endl;
		}
		if(ans.length()&&ans[0]!='0')
			cout<<ans<<endl;
		else
			cout<<-1<<endl;
	}
	return 0;
}


