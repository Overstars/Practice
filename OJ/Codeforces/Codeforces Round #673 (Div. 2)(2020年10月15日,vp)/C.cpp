//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
const int maxn=3e5+10,inf=0x3f3f3f3f,mod=1000000007;
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
int a[maxn],nex[maxn];//nex[i]记录w[0:i]串的最大公共串长度
void getnext(int *B,int n)
{
	nex[0]=0;
	for(int i=1,j=0;i<n;i++)/* n为B串长度 */
	{
//		j=nex[i-1];j为待计算位前一位对应的最大公共串的下一位(或前一位对应的最大公共串长度)
		while(B[j]!=B[i]&&j>0)//若匹配不上,尝试缩小公共子串,因为B串i之前的j个字符(B[i-j]~B[i-1])与开头的j个(B[0]~B[j-1])相同,直接在前面j个字符里找
			j=nex[j-1];//找最大公共子串的下一位与B[i]相同的最大公共子串,不能用j--,保证B[0]到B[i-1]这段目前匹配前缀后缀始终相同
		if(B[j]==B[i])//公共串下一位字符相同，公共最大长+1
			j++;
		nex[i]=j;//j为0~i最大公共串长度,若最终B[j]!=B[i],j=0
	}
}
vector<int>pos[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			pos[i].clear();
		for(int i=1;i<=n;i++)
			cin>>a[i],pos[a[i]].push_back(i);
//		getnext(a,n);
//		int len=n-nex[n-1];
//		cout<<"len="<<len<<endl;
//		for(int i=1;i<=len/2;i++)
//			cout<<-1<<' ';
		vector<int>ans(maxn,inf);
		for(int i=1;i<=n;i++)
		{
			int pre=0,rec=0;
			if(pos[i].empty())
				continue;
			for(int j=0;j<pos[i].size();j++)
			{
				rec=max(rec,pos[i][j]-pre);
				pre=pos[i][j];
			}
			rec=max(rec,n-pre+1);
			ans[rec]=min(ans[rec],i);
		}
		int pre=inf;
		for(int i=1;i<=n;i++)
		{
			pre=min(pre,ans[i]);
			if(pre<inf)
				cout<<pre<<' ';
			else
				cout<<-1<<' ';
		}
		cout<<endl;
	}
	return 0;
}
/*
求所有长度为k的子段的公共最小值
答案必定递减
*/

