#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+5,inf=0x3f3f3f3f,mod=1e9+7;
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
//#define DEBUG
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
	vector<int> rec[30];
	int n,k;
	cin>>n>>k>>s+1;
	for(int i=1;i<=n;i++)
	{
		rec[(int)(s[i]-'a')].push_back(i);
	}
	int ans=inf;
	for(int i=0;i<26;i++)
	{
		if(rec[i].size()<k)
			continue;
		for(int j=0;j+k-1<rec[i].size();j++)
			ans=min(ans,rec[i][j+k-1]-rec[i][j]+1);
	}
	cout<<(ans==inf?-1:ans)<<endl;
	return 0;
}


