#include<bits/stdc++.h>
#define rd(a) scanf("%d",&a)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define rev(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;
const int inf=1ll<<30;
const int N=1e5+5;
int w[N+N];
int pri_num,pri[N],pid[N],lp[N];
void seive(int n){
    pid[1]=-1;
    rep(i,2,n){
        if(~pid[i]){
            pid[i]=++pri_num;
            lp[i]=i;
            pri[pri_num]=i;
        }
        for(int j=1;j<=pri_num&&pri[j]*i<=n;j++){
            pid[pri[j]*i]=-1;
            lp[pri[j]*i]=pri[j];
            if(i%pri[j]==0)break;
        }
    }
}
struct BIT{
    ll a[N];
    void init(int n){
        for(int i=0;i<=n;i++)
            a[i]=0;
    }
    void add(int x,int v,int n){
        for(int i=x;i<=n;i+=i&-i){
            a[i]+=v;
        }
    }
    ll query(int x){
        ll res=0;
        for(int i=x;i;i-=i&-i){
            res+=a[i];
        }
        return res;
    }
}bit;
struct node{
    int pid,cnt;
};
struct edge{
    int to,w;
};
vector<edge>e[N+N];
int stk[N+N],top,dfn,leaf[N],dep[N+N],m;
ll ans=0;
void build(int m){
    top=0;
    dfn=0;
    stk[++top]=++dfn;
    dep[dfn]=0;
    leaf[1]=dfn;
    int tot=0;
    bit.init(m);
    for(int i=2;i<=m;i++){
        int x=i;
        vector<node>vec;
        while(x>1){
            int y=lp[x],cnt=0;
            while(x%y==0){
                x/=y;
                cnt++;
            }
            vec.push_back((node){pid[y],cnt});
        }
        int lca_dep=tot-bit.query(vec.back().pid-1);
     //   printf("%d %d\n",i,lca_dep);
        for(auto j:vec){
            bit.add(j.pid,j.cnt,m);
            tot+=j.cnt;
        }
        if(lca_dep!=dep[stk[top]]){
            while(dep[stk[top-1]]>lca_dep){
                e[stk[top-1]].push_back((edge){stk[top],dep[stk[top]]-dep[stk[top-1]]});
                top--;
            }
            if(dep[stk[top-1]]==lca_dep){
                e[stk[top-1]].push_back((edge){stk[top],dep[stk[top]]-dep[stk[top-1]]});
                top--;
            }
            else{
                e[++dfn].push_back((edge){stk[top],dep[stk[top]]-lca_dep});
                dep[dfn]=lca_dep;
                stk[top]=dfn;
            }
        }
        stk[++top]=++dfn;
        dep[dfn]=tot;
        leaf[i]=dfn;
    }
    while(top>1){
        e[stk[top-1]].push_back((edge){stk[top],dep[stk[top]]-dep[stk[top-1]]});
        top--;
    }
}
ll siz[N+N];
void dfs(int x){
    siz[x]=w[x];
  //  printf("%d %d\n",dep[x],w[x]);
    for(auto y:e[x]){
        dfs(y.to);
        siz[x]+=siz[y.to];
    }
}
void dfs_ans(int x){
  //  printf("%d\n",dep[x]);
    for(auto y:e[x]){
        if(siz[y.to]>siz[1]-siz[y.to]){
            ans-=1ll*(siz[y.to]*2-siz[1])*y.w;
            dfs_ans(y.to);
        }
    }
}
int main(){
    seive(N-5);
    while(~scanf("%d",&m)){
        ans=0;
        build(m);
        rep(i,1,m){
            int k;
            rd(k);
            w[leaf[i]]=k;
            ans+=1ll*k*dep[leaf[i]];
        }
        dfs(1);
        dfs_ans(1);
        printf("%lld\n",ans);
        for(int i=1;i<=dfn;i++){
            e[i].clear();
            w[i]=dep[i]=0;
        }
    }
    return 0;
}
/*
5
9 6 2 4 1
5
9 3 4 1 6
*/
