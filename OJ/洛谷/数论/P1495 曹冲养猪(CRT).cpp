#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int maxn=1005;
int a[maxn],b[maxn];
ll exgcd(ll a,ll b,ll &x,ll &y)//扩展欧几里得,要保证a>b
{//传递x,y的引用
    if(b == 0)
    {//推理1，终止条件
        x = 1;
        y = 0;
        return a;//找到gcd,一路返回上去
    }
    ll r = exgcd(b, a%b, x, y);
    //先得到更底层的x2,y2,再根据计算好的x2,y2计算x1，y1。
    //推理2，递推关系x1=y2,y1=x2-(a/b)*y2;
    ll t = y;
    y = x - (a/b) * y;//(a/b)向下取整
    x = t;
//    printf("x1=%d,y1=%d,r=%d\n",x,y,r);
    return r;
}
//扩展欧几里得求逆元
ll inv1(ll a,ll mod)
{
    ll x,y;
    exgcd(a,mod,x,y);
    return x=(x%mod+mod)%mod;//防止出现负数的情况
}
signed main()
{
//	freopen("P1495.in","r",stdin);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}//a[i]为模数n_i,b[i]为余数a_i
	int tot=1,ans=0;
	for(int i=1;i<=n;i++)
		tot*=a[i];
	for(int i=1;i<=n;i++)
	{
		int m_i=tot/a[i];
		ans+=b[i]*(m_i*inv1(m_i,a[i]));
		ans%=tot;
	}
	cout<<ans<<endl;
	return 0;
}
