//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;
const double eps=1e-9;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
struct node
{
	int val;
	node *nex;
	node(){}
	node(int val):
		val(val){nex=NULL;}
};
struct TreeNode
{
	int val;
	TreeNode *left,*right;
	TreeNode(){}
	TreeNode(int val):
		val(val){left=right=NULL;}
};
vector<int>G[maxn];
void dfs(TreeNode *x)
{
	if(x->left!=NULL)
	{
		G[(x->left)->val].push_back(x->val);
		dfs(x->left);
	}
	if(x->right!=NULL)
	{
		G[(x->right)->val].push_back(x->val);
		dfs(x->right);
	}
}
vector<int> now;
void get(int x)
{
	now.push_back(x);
	if(x==1)
		return;
	get(G[x][0]);
}
vector<vector<int>> sol(TreeNode *root,vector<int> &b)
{
	vector<vector<int>> ans;
	dfs(root);
	for(int &x:b)
	{
		now.clear();
		get(x);
		reverse(now.begin(),now.end());
		ans.push_back(now);
	}
	return ans;
}
int a[maxn]={0,1,2,3,4,5,6,7},n=7;
TreeNode *build(int n)
{
	if(n<1)
		return NULL;
	TreeNode *rt=new TreeNode;
	rt->val=a[1];
	queue<TreeNode*>q;
	q.push(rt);
	for(int i=2;i<=n;)
	{
		TreeNode *x=q.front();
		q.pop();
		x->left=new TreeNode(a[i++]);
		q.push(x->left);
		if(i>n)
			break;
		x->right=new TreeNode(a[i++]);
		q.push(x->right);
	}
	return rt;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	TreeNode *rt=build(n);
	vector<int>ques={1,2,3,4,5,6,7};
	vector<vector<int>> v=sol(rt,ques);
	for(auto &i:v)
	{
		for(auto &j:i)
			cout<<j<<' ';
		cout<<endl;
	}
	return 0;
}
/*
 *2021-04-03-12.26.57
*/

