//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=1e6+10,inf=0x3f3f3f3f,mod=1000000007;
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
char w[10005],t[maxn];
int nex[maxn],cnt[maxn];//nex[i]记录w[0:i]串的最大公共串长度
void getnext(char *B,int n)
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
}//https://www.cnblogs.com/c-cloud/p/3224788.html
int kmp(int m,int n)//m为A串长度,n为B串长度
{
	int ans=0,cmp=0;
	for(int i=0;i<m;i++){
		while(cmp>0&&t[i]!=w[cmp])//第cmp个位置匹配失败
			cmp=nex[cmp-1];//下一轮从匹配成功串的最大公共串的下一位开始匹配
		if(t[i]==w[cmp])//当前字符匹配成功,继续下一位
			cmp++;
		if(cmp==n){//子串匹配成功
			ans++;
			cmp=nex[cmp-1];//本题母串分割各部分间可以有公共部分
		}
	}
	return ans;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	cin>>t;
	int n=strlen(t),ans=n;
	getnext(t,n);
//	for(int i=0;i<n;i++)
//		printf("nex[%d]=%d\n",i,nex[i]);
	for(int i=n;i>0;i--)
	{
		cnt[i]++;//前缀[0,i-1]出现了
		cnt[nex[i-1]]+=cnt[i];//[0,i-1]的后半段公共前后缀
	}
	while(ans)
	{
		ans=nex[ans-1];
		if(cnt[ans]>=3)
			break;
//		cout<<"ans="<<ans<<endl;
//		cout.write(t,ans)<<endl;
	}
	if(!ans)
		cout<<"Just a legend"<<endl;
	else
		cout.write(t,ans)<<endl;
	return 0;
}
/*
qwertyqwertyqwerty
*/

