#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
//时间复杂度O(m*logm + m*logn)//对m条边sort+遍历m条边*并查集合并(路径压缩优化单次操作O(log*n))
//与边数m相关性很大,适合处理边数较少的图
const int inf=0x3f3f3f3f;
const int MAXN=5005;//稍大于节点数
int father[MAXN];//并查集优化记录各点祖宗
struct edge
{
	int u,v,w;//u,v为连接的节点,w为边权
} e[MAXN*MAXN];
bool cmp(edge x,edge y)
{
	return x.w<y.w;//边权从小到大排序
}
void init(int n)
{
	for(int i=1;i<=n;i++)
		father[i]=i;
}
int findfa(int x)//找节点x祖宗
{
	if(x!=father[x])
		father[x]=findfa(father[x]);//用*递归*的方法更改路径各点的标号
	return father[x];//返回祖宗(即标号)
}
int Merge(int a,int b)//合并节点a,b所在集合
{
	int p=findfa(a),q=findfa(b);
	if(p==q)
		return 0;
	if(p>q)//统一赋值为小的
		father[p]=q;
	else
		father[q]=p;
	return 1;
}
int kruskal(int n,int m)//节点数n,边数m
{
	int ans=0;
	for(int i=0;i<m;i++)//每次取出最小边
	{
		if(Merge(e[i].u,e[i].v))//判断不在同一集合
		{//在同一集合会形成回路
			ans+=e[i].w;
			n--;
			if(n==1)//已取完n-1条边
				return ans;
		}
	}
	return 0;//m条边遍历完,也不能使所有节点连接起来,即该图不连通
}
int main()
{
	int n,m;//节点数n,边数m
	while(cin>>n>>m){
		init(n);
		for(int i=0;i<m;i++)
			scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		sort(e,e+m,cmp);
		int ans=kruskal(n,m);
		if(ans)
			cout<<ans<<endl;
		else
			cout<<"orz"<<endl;
	}
	return 0;
}
