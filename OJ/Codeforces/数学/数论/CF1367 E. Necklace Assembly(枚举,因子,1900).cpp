//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
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
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n,k;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>s;
		int cnt[30]={0};
		for(char &ch:s)
			cnt[ch-'a']++;
		int ans=*max_element(cnt,cnt+26);//同一颜色
		vector<int>fac;
		for(int i=2;i<=k;i++)
			if(k%i==0)
				fac.push_back(i);
		for(int &f:fac)
		{//构造a=a+f,即f-beautiful环
			for(int i=n/f;i>=1;i--)
			{//枚举长度,环长i*f
				int now=0;
				for(int j=0;j<26;j++)
					now+=cnt[j]/i;//大于i的珠子数目
				if(now>=f)//数目大于f个
				{
					ans=max(ans,i*f);
					break;//间隔f不会更优,下一个
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
 *n颗珠子,颜色a-z,你要穿一个项链
 *找到一个顺时针移动k次仍相同的最大长度项链
*/

