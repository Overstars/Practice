#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=40018,inf=1e9;
struct edg{
    int nxt,to;
    double f;
}e[maxn];
int cnt,vis[maxn],head,tail,q[maxn],S,T,n,m,t,last[maxn],d[maxn];
double l,r,mid;
void add(int x,int y,double z){
    ++t;e[t].nxt=last[x];last[x]=t;e[t].to=y;e[t].f=z;
    ++t;e[t].nxt=last[y];last[y]=t;e[t].to=x;e[t].f=0;
}
struct dui{
    int from,to;
}qq[maxn];
int bfs(){
    head=tail=0;
    memset(d,-1,sizeof(d));
    q[++tail]=S;d[S]=0;
    while(head<tail){
        int u=q[++head];
        for(int i=last[u];i;i=e[i].nxt){
            int v=e[i].to;
            if(e[i].f&&d[v]==-1){
                d[v]=d[u]+1;
                q[++tail]=v;
            }
        }
    }
    return d[T]!=-1;
}
double dfs(int x,double h){
    if(x==T){return h;}
    double tmp=0,cp;
    for(int i=last[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(e[i].f&&d[v]==d[x]+1){
            cp=dfs(v,min(h-tmp,e[i].f));
            e[i].f-=cp;e[i^1].f+=cp;tmp+=cp;
            if(tmp==h){return tmp;}
        }
    }
    if(!tmp)d[x]=-2;
    return tmp;
}
double wtf;
int pd(double mid){
    memset(last,0,sizeof(last));t=1;
    for(int i=1;i<=m;++i){
        add(n+i,qq[i].from,inf);
        add(n+i,qq[i].to,inf);
        add(S,n+i,1.0);
    }
    for(int i=1;i<=n;++i){
        add(i,T,mid);
    }
    double pp,res=0;
    while(bfs()){
        while(pp=dfs(S,inf))res+=pp;
    }
    wtf=m-res;
    //cout<<res<<' '<<m<<endl;
    return (double(m)-res)>0;
}
void dfs1(int x){
    vis[x]=1;
    if(x>=1&&x<=n)cnt++;
    for(int i=last[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(e[i].f&&!vis[v])dfs1(v);
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        scanf("%d%d",&qq[i].from,&qq[i].to);
    }
    if(!m){puts("1");puts("1");return 0;}
    l=0,r=m+1;S=n+m+1,T=n+m+2;
    while(r-l>=1.0/n/n){
        //cout<<l<<' '<<r<<endl;
        mid=(l+r)/2;
        if(pd(mid))l=mid;
        else r=mid;
        printf("mid = %.3f,h = %.3f\n",mid,wtf);
    }
    pd(l);
    dfs1(S);
    printf("%d\n",cnt);
    for(int i=1;i<=n;++i){
        if(vis[i])
        printf("%d\n",i);
    }
    //system("pause");
    return 0;
}
