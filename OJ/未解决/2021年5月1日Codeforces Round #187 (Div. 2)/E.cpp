#include<iostream>
#include<stdio.h>
#include<cmath>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#define oo 0x3f3f3f3f
#define OO 0x3f3f3f3f3f3f3f3f
#define LL long long
#define res register int
#define STP system("pause")
using namespace std;
const int N=1e6,P=1e9+7;
//LL f[N+5];
//void Add(int x,LL w,int n){
//	while(x<=n){
//		f[x]=(f[x]+w)%P;
//		x+=(x&-x);
//	}
//	return ;
//}
//LL Ask(int x){
//	LL ans=0;
//	while(x){
//		ans=(ans+f[x])%P;
//		x-=(x&-x);
//	}
//	return ans;
//}
LL Fastpow(LL a,LL b,LL p){
	LL ans=1;
	while(b>0){
		if(b&1)	ans=ans*a%P;
		a=a*a%P;
		b>>=1;
	}
	return ans%P;
}
struct NODE{
	int l,r;
	LL flg,val;
}tree[(N<<2)+5];
//int n,m;
//LL a[N+5];
inline int lc(int x){
	return x<<1;
}
inline int rc(int x){
	return x<<1|1;
}
void Build(int x,int l,int r){
	tree[x].l=l,tree[x].r=r;
	if(l==r){
		tree[x].val=0;
		return ;
	}
	int mid=(l+r)>>1;
	Build(lc(x),l,mid);
	Build(rc(x),mid+1,r);
	tree[x].val=(tree[lc(x)].val*tree[rc(x)].val)%P;
	return ;
}
void Add(int x,int pos,LL w){
	if(tree[x].l==pos&&tree[x].r==pos){
		tree[x].val+=w;
		return ;
	}
	int Mid=(tree[x].l+tree[x].r)>>1;
	if(pos<=Mid)	Add(lc(x),pos,w);
	else	Add(rc(x),pos,w);
	tree[x].val=(tree[lc(x)].val*tree[rc(x)].val)%P;
	return ;
}
LL Ask(int x,int l,int r){
	if(l>r)	return 1;
	if(l<=tree[x].l&&r>=tree[x].r){
		return tree[x].val;
	}
//	spread(x);
	LL ans=1;
	int Mid=(tree[x].l+tree[x].r)>>1;
	if(l<=Mid)	ans*=Ask(lc(x),l,r);
	if(r>Mid)	ans*=Ask(rc(x),l,r);
	return ans;
}
int a[N+5],b[N+5],cnt,c[N+5];
void discrete(int n){
	memcpy(b,a,sizeof(a));
	sort(b+1,b+n+1);
	for(int i=1;i<=n;++i)
		if(i==1||b[i]!=b[i-1])
			c[++cnt]=b[i];
	return ;
}
int Q(int x){
	return lower_bound(c+1,c+cnt+1,x)-c;
}
int vis[N+5],ed[N+5],st[N+5];
int main(){
	int n,mx=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	discrete(n);
	mx=cnt;
	for(int i=1;i<=n;++i){
		a[i]=Q(a[i]);
		ed[a[i]]=i;
		if(st[a[i]]==0)	st[a[i]]=i;
	}
	Build(1,1,mx);
//	for(int i=1;i<=mx;++i){
//		if(ed[i]){
//			Add(i,1,mx);
//		}
//	}

	LL ans=0;
	for(int i=1;i<=n;++i){
		if(st[a[i]]==i)	Add(1,a[i],1);
		++vis[a[i]];
		Add(1,a[i],Fastpow(c[a[i]],vis[a[i]],P));
//		if(ed[a[i]]==i){
//			ans=(ans+Ask(1,1,a[i])-Ask(1,1,a[i]-1))%P;
//			if(a[i]==a[1])	ans-=1;
//			cout<<ans<<'\n';
//		}
	}
	for(int i=1;i<=cnt;++i)	vis[i]=0;
	for(int i=n;i;--i){
		++vis[a[i]];
		ans=(ans+Ask(1,1,a[i]-1)*Fastpow(c[a[i]],vis[a[i]],P)%P)%P;
		Add(1,a[i],-Fastpow(c[a[i]],vis[a[i]],P));
//		if(st[a[i]]==i)	Add(1,a[i],-1);
//		cout<<ans<<'\n';
	}
	cout<<ans<<'\n';
	return 0;
}
