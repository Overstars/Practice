#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <set>
#include <algorithm>
#define MAXN 30050
using namespace std;
/*
输入格式：
第一行两个正整数n和q，表示点的个数，查询和询问的总次数。

接下来n-1行，每行两个正整数u、v、w，表示u和v两个点之间有一条边权为w的边。

接下来q行，格式为1 u v或2 u v w。如果为1 u v操作，
你需要输出u到v的路径上所有子路径经过的边的边权的xor值的和是多少；
如果为2 u v w操作，你需要把u到v这条边的边权改为w，保证这条边存在。

输出格式：
对于每个1操作，输出答案。*/
int n, q, son[MAXN], size[MAXN], dep[MAXN], fa[MAXN], top[MAXN], id[MAXN], b[MAXN], num[MAXN], ecnt, tcnt, ed[MAXN];
struct node
{
    int v, w;//线段树维护树上边权
    node *next;
    node(){}
    node(int _v, int _w, node *_n) {
        v = _v, w = _w, next = _n;
    }
}pool[MAXN<<2], *h[MAXN];
struct node2
{
    int num0, num1, rev;//线段树维护区间特定位0/1个数
    node2 operator + (const node2 &x){
        node2 t;
        t.num0 = num0 + x.num0;
        t.num1 = num1 + x.num1;
        t.rev = 0;
        return t;
    }
}t[25][MAXN<<3];
inline void addedge(int u, int v, int w)
{
    node *p1 = &pool[ecnt++], *p2 = &pool[ecnt++];
    *p1 = node(v, w, h[u]), h[u] = p1;
    *p2 = node(u, w, h[v]), h[v] = p2;
}
void dfs1(int u)
{
    size[u] = 1;
    for(node *p = h[u]; p; p = p->next){
        if(p->v != fa[u]){
            //cout<<u<<' '<<p->v<<' '<<b[u]<<' '<<p->w<<' '<<b[p->v]<<' ';
            b[p->v] = b[u]^p->w;//b为异或的前缀和
            ed[p->v] = p->w;//以点代边
            //cout<<b[p->v]<<endl;
            fa[p->v] = u;
            dep[p->v] = dep[u]+1;
            dfs1(p->v);
            size[u] += size[p->v];
            if(size[p->v] > size[son[u]]) son[u] = p->v;
        }
    }
}
void dfs2(int u, int t)
{
    id[u] = ++tcnt;
    num[tcnt] = b[u];
    top[u] = t;
    if(!son[u]) return;
    dfs2(son[u], t);
    for(node *p = h[u]; p; p = p->next){
        if(!id[p->v]) dfs2(p->v, p->v);
    }
}
void build(int k, int u, int l, int r){
    if(l == r){
        if((num[l]>>k)&1)
            t[k][u].num1 = 1;
        else t[k][u].num0 = 1;
        return;
    }
    int mid = (l+r)>>1;
    build(k, u<<1, l, mid); build(k, u<<1|1, mid+1, r);
    t[k][u] = t[k][u<<1] + t[k][u<<1|1];
    //cout<<k<<' '<<u<<' '<<l<<' '<<r<<' '<<t[k][u].num0<<' '<<t[k][u].num1<<' '<<t[k][u].rev<<endl;
}
void pushdown(int k, int u){
    if(t[k][u].rev == 0) return;
    //cout<<"IN "<<k<<' '<<u<<endl;
    swap(t[k][u<<1].num0, t[k][u<<1].num1);
    swap(t[k][u<<1|1].num0, t[k][u<<1|1].num1);
    t[k][u<<1].rev ^= 1;
    t[k][u<<1|1].rev ^= 1;
    t[k][u].rev = 0;
}
void rev(int k, int u, int l, int r, int tl, int tr){
    if(tl <= l && r <= tr){
        swap(t[k][u].num0, t[k][u].num1);
        t[k][u].rev ^= 1;
        return;
    }
    int mid = (l+r)>>1;
    pushdown(k, u);
    if(tl <= mid)
        rev(k, u<<1, l, mid, tl, tr);
    if(mid < tr)
        rev(k, u<<1|1, mid+1, r, tl, tr);
    t[k][u] = t[k][u<<1] + t[k][u<<1|1];
}
void change(int u, int w){
    for(int i = 0; i <= 10; i++){
        if(((w^ed[u])>>i)&1)//翻转子树
            rev(i, 1, 1, n, id[u], id[u]+size[u]-1);
    }
    ed[u] = w;
}
node2 query(int k, int u, int l, int r, int tl, int tr){
    if(tl <= l && r <= tr){
        return t[k][u];
    }
    int mid = (l+r)>>1;
    pushdown(k, u);
    node2 ret; ret.num0 = ret.num1 = 0;
    if(tl <= mid) ret = ret + query(k, u<<1, l, mid, tl, tr);
    if(mid < tr) ret = ret + query(k, u<<1|1, mid+1, r, tl, tr);
    //cout<<k<<' '<<u<<' '<<l<<' '<<r<<' '<<t[k][u].num0<<' '<<t[k][u].num1<<endl;
    return ret;
}
long long Query(int u, int v){
    long long ret = 0;
    int U = u, V = v;
    for(int i = 0; i <= 10; i++){//不超过2^10
        u = U, v = V;
        //cout<<i<<endl;
        node2 res; res.num0 = res.num1 = 0;
        while(top[u] != top[v]){
            if(dep[top[u]] < dep[top[v]])
                swap(u, v);
            res = res + query(i, 1, 1, n, id[top[u]], id[u]);
            //cout<<id[top[u]]<<' '<<id[u]<<' '<<res.num0<<' '<<res.num1<<endl;
            u = fa[top[u]];
        }
        if(dep[u] > dep[v])
            swap(u, v);
        res = res + query(i, 1, 1, n, id[u], id[v]);
        //cout<<id[u]<<' '<<id[v]<<' '<<res.num0<<' '<<res.num1<<endl;
        ret += (1LL<<i)*res.num0*res.num1;
    }
    return ret;
}
int main()
{
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    int opt, u, v, w;
    scanf("%d%d", &n, &q);
    for(int i = 1; i < n; i++)
        scanf("%d%d%d", &u, &v, &w), addedge(u, v, w);
    dep[1] = 1;
    dfs1(1);
    dfs2(1, 1);
    //for(int i = 1; i <= n; i++) cout<<dep[i]<<' ';cout<<endl;
    for(int i = 0; i <= 10; i++) build(i, 1, 1, n);
    while(q--){
        scanf("%d%d%d", &opt, &u, &v);
        if(opt == 1){
            printf("%lld\n", Query(u, v));
        }
        else{
            scanf("%d", &w);
            if(u != fa[v])//一定有一个是另一个爸爸,该边权即在儿子上
                swap(u, v);
            change(v, w);//将子树01翻转
        }
    }
    return 0;
}
