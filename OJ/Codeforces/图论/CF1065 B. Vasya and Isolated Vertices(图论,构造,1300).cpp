#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int main()
{
	ll n,m,ans1=0,ans2=0;
	cin>>n>>m;
	if(m==0)
	{
		cout<<n<<' '<<n;
		exit(0);
	}
	if(m>=(n/2)+(n%2))//贪心
		ans1=0;
	else
		ans1=n-m*2;
	ans2=(1+(ll)sqrt(1+8*m))/2;
	if(ans2*(ans2-1)/2<m)
		ans2++;//解出连接节点数
	cout<<ans1<<' '<<n-ans2<<endl;
	return 0;
}
