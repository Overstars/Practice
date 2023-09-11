//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
#define int ll
const int maxn=2e6+10,inf=0x3f3f3f3f,mod=1000000007,mod2=1000000009;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
struct node
{
    ll hash1,hash2;
}a[maxn+5];
map<pair<int,int>,int>mp;
signed main()
{
    int T;
    read(T);
    a[1].hash1 = a[1].hash2 = 1;
    a[2].hash1 = a[2].hash2 = 2;
    mp[{1,1}]=1;
    mp[{2,2}]=2;
    for(int i = 3; i < maxn; i++)
    {
        a[i].hash1 = (a[i - 1].hash1 + a[i - 2].hash1) % mod2;
        a[i].hash2 = (a[i - 1].hash2 + a[i - 2].hash2) % mod;
        pair<int,int>p(a[i].hash1,a[i].hash2);
        mp[p]=i;
    }
    while(T--)
    {
        int A, B, C;
        read(A);
        ll ans1 = 0, ans3 = 0, ans5 = 0;
        ll ans4 = 0, ans2 = 0, ans6 = 0;
        for(int i = 1, x; i <= A; i++)
        {
            read(x);
            if(x == 1) ans1 += a[i].hash1, ans1 %= mod2, ans2 += a[i].hash2, ans2 %= mod;
        }
        read(B);
        for(int i = 1, x; i <= B; i++)
        {
            read(x);
            if(x == 1) ans3 += a[i].hash1, ans3 %= mod2, ans4 += a[i].hash2, ans4 %= mod;
        }
        read(C);
        for(int i = 1, x; i <= C; i++)
        {
            read(x);
            if(x == 1)  ans5 += a[i].hash1, ans5 %= mod2, ans6 += a[i].hash2, ans6 %= mod;
        }
        ll aa = ((ans1 * ans3)%mod2 - ans5)%mod2;
        aa = (aa + mod2) % mod2;
        ll bb = ((ans2 * ans4)%mod - ans6)%mod;
        bb = (bb + mod) % mod;
        printf("%d\n",mp[{aa,bb}]);
    }
    return 0;
}



