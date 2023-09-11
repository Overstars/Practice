//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
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
	int h,c;
	node(int h=0,int c=0):
		h(h),c(c){}
};
int h[maxn],a[maxn],b[maxn],c[maxn];
bool cmp1(const node &x,const node &y)
{
	return x.h<y.h;//先吃能吃的
}
bool cmp2(const node &x,const node &y)
{
	return x.h+x.c>y.h+y.c;//越大越先吃
}
vector<node>r1,r2;
int solve(int x,int y,int z)
{
	int sum=-INF,ans=-INF;
//	if(z-y>=0)
//		p=upper_bound(r1.begin(),r1.end(),node(x,0),cmp1)-r1.begin()-1;//第一个h小于等于x的
////	fprintf(stderr,"sub=%d,p=%d\n",z-y,p);
//	if(p==-1)
//	{//全都比x大,x打头阵
//		if(sum<x)
//		{
//			ans+=x-sum;
//			sum=x;
//		}
//		sum+=z-y;
//	}
	if(x!=0||y!=0||z!=0)
	{
		node now=node(x,z-y);
		if(z-y>=0)
		{
			r1.insert(lower_bound(r1.begin(),r1.end(),now,cmp1),now);
//			r1.push_back(node(x,z-y));
//			sort(r1.begin(),r1.end(),cmp1);
		}
		else{
			r2.insert(lower_bound(r2.begin(),r2.end(),now,cmp2),now);
//			r2.push_back(node(x,z-y));
//			sort(r2.begin(),r2.end(),cmp2);
		}
	}
//	if(!r1.empty())
//		ans=min(ans,r1[0].h);
//	if(!r2.empty())
//		ans=min(ans,r2[0].h);
	for(int i=0;i<r1.size();i++)
	{
		if(sum<r1[i].h)
		{
//			if(ans==-INF)
//				ans=0;
			ans+=r1[i].h-sum;//补齐到h
			sum=r1[i].h;
		}
		sum+=r1[i].c;
//		if(i==p)//
//		{
//			if(sum<x)
//			{
//				ans+=x-sum;
//				sum=x;
//			}
//			sum+=z-y;
//		}
	}
//	p=INF;
//	if(z-y<0)
//		p=upper_bound(r2.begin(),r2.end(),node(x,z-y),cmp2)-r2.begin()-1;//第一个h+c小于等于x+z-y的
//	if(p==-1)
//	{//这是第一个
//		if(sum<x)
//		{
//			ans+=x-sum;
//			sum=x;
//		}
//		sum+=z-y;
//	}
//	fprintf(stderr,"sub=%d,p=%d\n",z-y,p);
	for(int i=0;i<r2.size();i++)
	{
		if(sum<r2[i].h)
		{
			ans+=r2[i].h-sum;//补齐s
			sum=r2[i].h;
		}
		sum+=r2[i].c;
//		if(i==p)//
//		{
//			if(sum<x)
//			{
//				ans+=x-sum;
//				sum=x;
//			}
//			sum+=z-y;
//		}
	}
	return ans;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n,q,x,y,z;
	read(n);
	for(int i=1;i<=n;i++)
		read(h[i]);
//		cin>>h[i];
	for(int i=1;i<=n;i++)
	{
		read(a[i],b[i]);
//		cin>>a[i]>>b[i];
		if(b[i]-a[i]>=0)
			r1.push_back(node(h[i],b[i]-a[i]));
		else
			r2.push_back(node(h[i],b[i]-a[i]));
	}
	sort(r1.begin(),r1.end(),cmp1);
	sort(r2.begin(),r2.end(),cmp2);
//	cin>>q;
	read(q);
//	#define endl '\n'
	fprintf(stderr,"ans = ");
	printf("%lld\n",solve(0,0,0));
//	cerr<<"ans = ";
//	cout<<solve(0,0,0)<<endl;
	while(q--)//答案可能为负
	{
		read(x,y,z);
		fprintf(stderr,"ans = ");
		printf("%lld\n",solve(x,y,z));
//		cin>>x>>y>>z;
//		cerr<<"ans = ";
//		cout<<solve(x,y,z)<<endl;
	}
	return 0;
}
/*
 * 2021-05-30-09.55.59
 * C:\Users\dell\Desktop\C++\OJ\未解决\2021年5月30日The 16th Heilongjiang Provincial Collegiate Programming Contest\L.cpp
 * 战斗力增加c=b-a
 * 将c分为>=0和<0两部分
 * 先吃>=0的那部分,按h从小到大贪心
 * c<0那部分按照h+c从大到小排序
*/

