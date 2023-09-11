#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
inline int read()
{
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9'){ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}
int n,pos[100008],l,r,ans;
struct node{
    int s,p;
}a[100008];
map<int,int> m;
set<int> s;
set<int>::iterator si;
bool vis[100008];
inline bool cmp(const int a,const int b){return a<b;}
inline bool cmp2(const node a,const node b){return a.s>b.s;}
int main()
{
    n=read();
    for(int i=1;i<=n;i++){
        a[i].s=read();a[i].p=read();
        pos[i]=a[i].p;
    }
    sort(pos+1,pos+n+1,cmp);
    for(int i=1;i<=n;i++)    m[pos[i]]=i;
    sort(a+1,a+n+1,cmp2);
    s.insert(a[1].p);
    for(int i=2;i<=n;i++){
        if(*s.begin()<a[i].p){
            si=--s.upper_bound(a[i].p);
            l=m[*si];r=m[a[i].p];
            if(pos[r]-pos[l]<=a[i].s&&!vis[l]){
                for(int j=l;j<r;j++)    vis[j]=1;
            }
        }
        if(*--s.end()>a[i].p){
            si=s.upper_bound(a[i].p);
            l=m[a[i].p];r=m[*si];
            if(pos[r]-pos[l]<=a[i].s&&!vis[l]){
                for(int j=l;j<r;j++)    vis[j]=1;
            }
        }
        s.insert(a[i].p);
    }
    for(int i=1;i<n;i++){
        if(vis[i])    ans+=pos[i+1]-pos[i];
    }
    cout<<ans;
    return 0;
}
