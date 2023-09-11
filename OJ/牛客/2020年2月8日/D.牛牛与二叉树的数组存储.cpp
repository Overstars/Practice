#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
int a[maxn<<1];
struct node
{
	int I,X,Y,Z;
	node(int a,int b,int c,int d):
		I(a),X(b),Y(c),Z(d){}
};
bool cmp(const node &x,const node &y)
{
	return x.I<y.I;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,cnt=0;
	memset(a,-1,sizeof(a));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=-1)
			cnt++;
	}
	printf("The size of the tree is %d\n",cnt);
	printf("Node %d is the root node of the tree\n",a[1]);
	vector<node> ans;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==-1)
			continue;
		ans.push_back(node(a[i],a[i/2],a[i*2],a[i*2+1]));
	}
	sort(ans.begin(),ans.end(),cmp);
	for(auto &i:ans)
		printf("The father of node %d is %d, the left child is %d, and the right child is %d\n",i.I,i.X,i.Y,i.Z);
	return 0;
}


