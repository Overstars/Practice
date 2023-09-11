#include<bits/stdc++.h>
using namespace std;
const int maxn=40;
int m[maxn],p[maxn];
struct node
{
	int val;
	node *lc,*rc;
	node()
	{
		val=0;
		lc=rc=NULL;
	}
};
node* build(int ml,int mr,int pl,int pr)
{
	if(pl>pr)
		return NULL;
	node *pt=(node*)malloc(sizeof(node));
	if(pl==pr)
	{
		pt->val=p[pl];
		pt->lc=pt->rc=NULL;
		return pt;
	}
	int fa=p[pl],barrier=ml;
	pt->val=fa;//通过先序确定父节点
	while(m[barrier]!=fa)//在中序区间找,分割成两段
		barrier++;
	int len=barrier-ml;//左子树节点数
	pt->lc=build(ml,barrier-1,pl+1,pl+len);
	pt->rc=build(barrier+1,mr,pl+len+1,pr);
	return pt;
}
void dfs(node *rt)
{
	if(rt==NULL)
		return;
	printf("%d\n",rt->val);
	dfs(rt->lc);
	dfs(rt->rc);
}
void bfs(node *rt)
{
	queue<node*> QAQ;
	vector<int>ans;
	QAQ.push(rt);
	while(!QAQ.empty())
	{
		node *now=QAQ.front();
		QAQ.pop();
		if(now==NULL)
			break;
		ans.push_back(now->val);
		if(now->rc!=NULL)
			QAQ.push(now->rc);
		if(now->lc!=NULL)
			QAQ.push(now->lc);
	}
	for(int i=0;i<ans.size();i++)
		printf("%d%c",ans[i],(i==(int)ans.size()-1)?'\n':' ');
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>m[i];
	for(int i=1;i<=n;i++)
		cin>>p[i];
	node *root=build(1,n,1,n);
//	dfs(root);
	bfs(root);
	return 0;
}
