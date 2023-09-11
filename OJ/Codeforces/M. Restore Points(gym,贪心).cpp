#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define mod 1000000007
#define PI acos(-1)
#define fi first
#define se second
#define lowbit(x) (x&(-x))
#define mp make_pair
#define pb push_back
#define si size()
#define E exp(1.0)
#define fixed cout.setf(ios::fixed)
#define fixeds(x) setprecision(x)
#define IOS ios::sync_with_stdio(false);cin.tie(0)
 using namespace std;
inline ll read(){
    char c=getchar();
    ll f=1,x=0;
    while(c<'0'||c>'9'){
        if(c=='-')
            f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+(c^'0');
        c=getchar();
    }
    return x*f;
}
ll gcd(ll a,ll b){ return b==0?a:gcd(b,a%b);}//最大公因数
/*最小公倍数lcm(a,b)=a*b/gcd(a,b);
gcd(ka,kb)=k*gcd(a,b);
gcd(s/a,s/b)=s/gcd(a,b);
gcd(x^a-1,x^b-1)=x^gcd(a,b)-1;
gcd(f[a],f[b])=f[gcd(a,b)];
lcm(ka,kb)=k*lcm(a,b);
lcm(f[a],f[b])=f[lcm(a.b)];*/
const int N=1e5+5;
ll a[100],flag[100],s=0,n,sum,c[220],k,rr[220],flagg=0,fflag=0;
bool ass=0;
void dfs(int x,int t)
{
    if(sum==s)
    {   if(t==n-1&&fflag==0){
             flagg=0;
             for(int i=1;i<=t;i++){
            if(c[i]==0){flagg++;break;}

          }
     if(flagg==0){
     //可行
         for(int i=1;i<=t;i++){
         rr[i]=c[i];
          fflag++;
          }

     }
    // flagg--;
     }
       return ;
    }
    if(x==n+1)
    {
        return ;
    }
    for(int i=0;i<n;i++)
    if(!flag[i])
    {
        flag[i]=1;
        sum+=a[i];
        t++;
        c[t]=a[i];
        dfs(x+1,t);
        sum-=a[i];
        flag[i]=0;
        c[t]=0;
        t--;
       // c[t]=0;
       // t--;
      //   dfs(x+1,t);
    }
}
int main()
{
  ll t=read();
  while(t--){
         n=read();
         s=0;
         flagg=0;
         fflag=0;
        memset(flag,0,sizeof(flag));

        ass=0,sum=0;
        for(int i=1;i<=n*(n-1)/2;i++)
        {
            cin>>a[i];
            s=max(s,a[i]);
        }
        sort(a+1,a+1+n);
        dfs(0,0);
        ll add=0;
      //  printf("QAQ %lld\n",s);

    for(int i=0;i<=n-1;i++){
         add=add+rr[i];
        printf("%lld ",add);

    }
 printf("\n");
  }



return 0;

}  //DFS背包
