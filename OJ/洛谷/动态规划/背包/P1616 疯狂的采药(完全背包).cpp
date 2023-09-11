#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<climits>
#include<cmath>
#include<iomanip>//控制输出,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
//#define DEBUG
int v[10005],w[10005],f[100005];
inline int maxi(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	int t,m;//时间,数目
	cin>>t>>m;
	for(int i=1;i<=m;i++)
		cin>>v[i]>>w[i];
	for(int i=1;i<=m;i++)
		for(int j=0;j<=t;j++)
			for(int k=0;v[i]*k<=j;k++)
				f[j]=maxi(f[j],f[j-k*v[i]]+k*w[i]);
	cout<<f[t]<<endl;
	return 0;
}
