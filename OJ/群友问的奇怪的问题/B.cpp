#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
struct TreeNode {
	int val;
	struct TreeNode *left,*right;
	TreeNode(){}
	TreeNode(int val):
		val(val){left=right=NULL;}
};
class Solution {
public:
	const static int maxn=1e5+10;
	int cnt[maxn]={0},f[maxn]={0};//>18层就不可能
	void dfs(TreeNode* root,int dep)
	{
		cnt[dep]++;
		if(root->left!=NULL)
			dfs(root->left,dep+1);
		if(root->right!=NULL)
			dfs(root->right,dep+1);
	}
	void del(TreeNode* root,int dep)
	{
		if(root->left!=NULL)
			del(root->left,dep+1);
		if(root->right!=NULL)
			del(root->right,dep+1);
		if(root->left!=NULL)
		{
			if(cnt[dep+1]!=f[dep+1])
				root->left=NULL;
		}
		if(root->right!=NULL)
		{
			if(cnt[dep+1]!=f[dep+1])
				root->right=NULL;
		}
	}
	void check(TreeNode* root) {
		if(root==NULL)
			return;
		printf("%d\n",root->val);
		check(root->left);
		check(root->right);
	}
	TreeNode* solve(TreeNode* root) {
		f[1]=1;
		for(int i=2;i<=20;i++)
			f[i]=f[i-1]*2;
		dfs(root,1);
		del(root,1);
		check(root);
		return root;
	}
} s;
int a[maxn]={0,1,2,3,4,5,6,7,8,9,10};
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
//		printf("now = %d\n",a[i]);
		x->left=new TreeNode(a[i++]);
		q.push(x->left);
		if(i>n)
			break;
		x->right=new TreeNode(a[i++]);
		q.push(x->right);
	}
	return rt;
}
int main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t,n=10;
	TreeNode *rt=build(n);
	printf("wtf\n");
	s.solve(rt);
	return 0;
}
/*
 *2021-04-04-19.49.36
*/
