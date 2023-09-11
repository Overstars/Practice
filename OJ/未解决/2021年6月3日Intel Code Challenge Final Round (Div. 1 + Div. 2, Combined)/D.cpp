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
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define res register int
#define sz(x)	int(x.size())
#define STP system("pause")
using namespace std;
const int N=1e5;
struct LIST{
	int pre,nxt;
	int pos;
}lst[N+5];
struct NODE{
	int val,pos;
	bool operator <(const NODE &r)const{
		return val<r.val;
	}
}node[N+5];
priority_queue<NODE> q;
char s[N+5];
int vis[30];
int main(){
	int k;
	scanf("%d",&k);
	scanf("%s",s+1);
	int n=strlen(s+1);
//	cout<<s<<'\n';
	rep(i,1,n){
		node[i].val=s[i]-'a'+1;
		node[i].pos=i;
		vis[node[i].val]+=1;
		q.push(node[i]);
		lst[i].pre=i-1;
		lst[i].nxt=i+1;
		lst[i].pos=i;
	}
	int flg=0;
	while(sz(q)){
		NODE x=q.top();
		q.pop();
		int y=x.pos,z=x.val;
		if(flg&&z!=flg)	break;
		if(lst[y].nxt-lst[y].pre-1<k){
			if(lst[y].nxt!=n+1)	lst[lst[y].nxt].pre=lst[y].pre;
			if(lst[y].pre!=0)	lst[lst[y].pre].nxt=lst[y].nxt;
			--vis[z];
		}
		else if(flg==0){
			flg=z;
		}
	}
	rep(i,1,26)
		while(vis[i]){
			cout<<char('a'+i-1);
			--vis[i];
		}
	return 0;
}
