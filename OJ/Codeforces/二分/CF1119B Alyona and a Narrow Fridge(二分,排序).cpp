#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
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
ll a[10005],n,h;
//#define DEBUG
bool cmp(const ll &a,const ll &b)
{
	return a>b;
}
bool judge(ll x)//前x个
{
	vector <ll> tem;//不能在原数组内操作
	for(int i=0;i<x;i++)
		tem.push_back(a[i]);
	sort(tem.begin(),tem.end(),cmp);
	ll tot=0;
	for(int i=0;i<tem.size();i+=2)
	{
		tot+=tem[i];
	}
	#ifdef DEBUG
	cout<<"mid="<<x<<",tot="<<tot<<endl;
	#endif // DEBUG
	return tot<=h;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("CF1119B.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	cin>>n>>h;
	#ifdef DEBUG
	cout<<"n="<<n<<",h="<<h<<endl;
	#endif // DEBUG
	for(int i=0;i<n;i++)
		cin>>a[i];
	ll l=1,r=n,mid,ans=1;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(judge(mid))
			ans=mid,l=mid+1;
		else
			r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}
