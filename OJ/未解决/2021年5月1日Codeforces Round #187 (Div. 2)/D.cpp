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
string pow(string s,int b)
{
	string ans;
	for(int i=0;i<b;i++)
		ans+=s;
//	while(b)
//	{
//		if(b&1)
//			ans+=s;
//		ans+=ans;
//		b>>=1;
//	}
	return ans;
}
void solve()
{
	int b,d,len=0,have=0;
	string a,c;
	cin>>b>>d>>a>>c;
	int n=a.length(),m=c.length();
	vector<int> nex(m,0),cnt(m,0);
	for(int i=0;i<m;i++)
	{//nex[i]表示从c[i]开始经过一个a到c的哪一位
		int pos=i,num=0;
		for(int j=0;j<n;j++)
		{
			if(c[pos]==a[j])
			{
				pos++;
				if(pos==m)
					num++,pos=0;
			}
		}
//		printf("%d,%d\n",pos,num);
		cnt[i]=num;
		nex[i]=pos;
	}
	int ans=0,pos=0;
	for(int i=0;i<b;i++)
	{
		ans+=cnt[pos];
		pos=nex[pos];
	}
	cout<<ans/d<<endl;
	exit(0);
}
signed main(signed argc, char const *argv[])
{
	solve();
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int b,d,len=0,have=0;
	string a,c;
	cin>>b>>d>>a>>c;
	int n=a.length(),m=c.length();
	string s=pow(a,10000);
	map<char,int>mp;
	for(int l=0,r=0;l<s.length();l++)
	{
//		printf("%d\n",l);
		if(l%n==0)
		{
			len++;//循环节
			mp.clear();
			for(char &ch:a)
				mp[ch]++;
		}
		mp[s[l]]--;
		if(s[l]==c[r])
		{
			if(r+1==m)
			{
				have++;
				if(mp[c[0]]==0)
				{//找到了循环节
					break;
				}
			}
			r=(r+1)%m;
		}
	}
	s=pow(a,b%len);
	int cnt=0;
	for(int l=0,r=0;l<s.length();l++)
	{
		if(s[l]==c[r])
		{
			if(r+1==m)
			{
				cnt++;
			}
			r=(r+1)%m;
		}
	}
//	printf("len=%d,have=%d,cnt=%d\n",len,have,cnt);
	cout<<((b/len*have+cnt)/d)<<endl;
//	cout<<pow(a,b)<<endl;
	return 0;
}
/*
6557487 3
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaa
*/
/*
 * 2021-05-01-16.02.05
 * 长度不超过100,找循环节
 * 统计[a,b]中有多少个c
 * b%len
*/

