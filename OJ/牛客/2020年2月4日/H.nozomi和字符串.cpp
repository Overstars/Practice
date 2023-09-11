#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+5,inf=0x3f3f3f3f,mod=1000000007;
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
//#define DEBUG
int dp[2][maxn];
char s[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,k,ans=1;//
	cin>>n>>k>>s+1;
	for(int i=1,j=1,c=0;j<=n;)
	{//0->1
		if(c>k)
		{
			if(s[i]=='0')
				c--;
			i++;
		}
		else{
			if(s[j]=='0')
				c++;
			if(c<=k)
				ans=max(ans,j-i+1);
			j++;
		}

	}
	for(int i=1,j=1,c=0;j<=n;)
	{//1->0
		if(c>k)
		{
			if(s[i]=='1')
				c--;
			i++;
		}
		else{
			if(s[j]=='1')
				c++;
			if(c<=k)
				ans=max(ans,j-i+1);
			j++;
		}
	}
	cout<<ans<<endl;
	return 0;
}


