#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
#include <set>
#include <stack>
//#include <unordered_map>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define debug(x) cout<<x<<endl
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
typedef long long ll;
using namespace std;
const int MAXN=2e5+50;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
//::iterator it;
inline int read(){
    int s=0,w=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    return s*w;
}
int dep[MAXN],sz[MAXN],fath[MAXN],dfn[MAXN];
vector<int>p[MAXN];
void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	for(auto y:p[x]){
		if(y==fa)continue;
		dfs(y,x);
	}
}
struct sa{
	int dd;
	int ss;
}yz[MAXN];
int d[MAXN];
int cmp(sa a,sa b){
	return a.ss<b.ss;
}
int main()
{
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
    	int u,v;
    	cin>>u>>v;
    	p[u].pb(v);
    	p[v].pb(u);
    	d[u]++;
    	d[v]++;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
    	if(d[i]==1){
    		yz[++cnt].dd=i;
    	}
    }
    dfs(yz[cnt].dd,0);
    //cout<<yz[cnt].dd<<endl;


    for(int i=1;i<=cnt;i++){
    	yz[i].ss=dep[yz[i].dd];
    }
    sort(yz+1,yz+cnt+1,cmp);
    for(int i=1;i<=cnt;i++){
    	cout<<yz[i].dd<<" "<<yz[i].ss<<endl;
    }
    cout<<ceil(cnt/2.0)<<endl;
    for(int i=1;i<=cnt/2;i++){
    	cout<<yz[i].dd<<" "<<yz[cnt-i+1].dd<<endl;
    }
    if(cnt&1){
    	cout<<yz[cnt/2+1].dd<<" "<<yz[1].dd<<endl;
    }
    return 0;
}
/*

*/

 
 