/*给定n个点(1e4)，m条边的无向图(1e4)，可以从图中删除一条边，问删除哪些边可以使图变成一个二分图。*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
int cnt,head[maxn];
struct edge
{
	int v,nex;
} e[maxn<<1];
inline add(int u,int v)
{
	e[++cnt].v=v;
	e[cnt].nex=head[u];
	head[u]=cnt;
}
int main()
{

}
