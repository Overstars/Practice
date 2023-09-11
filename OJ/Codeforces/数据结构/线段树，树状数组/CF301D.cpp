#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+10;
struct BinaryIndexTree
{
	int c[maxn],sum[maxn],n;
	#define lowbit(x) ((x)&(-x))
	void init(int x)
	{
		this->n=x;
		memset(c,0,sizeof(c));
		memset(sum,0,sizeof(sum));
	}
	void add(int k,ll val)
	{
		for(int i=k;i<=n;i+=lowbit(i))
		{
			c[i]+=val;
			sum[i]+=val*(k-1);
		}
	}
	ll query(int k)
	{
		ll ret=0;
		for(int i=k;i;i-=lowbit(i))
			ret += c[i]*k - sum[i];
		return ret;
	}
	void radd(int l,int r,ll val)
	{
		add(l,val);
		add(r+1,-val);
	}
} bit;
struct ques
{
	int l,r,id;
	ques(int a=0,int b=0,int c=0):
		l(a),r(b),id(c){}
};
vector<int> vec[maxn];
int main()
{
	std::ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1),pos(n+1);
	for(int i=1;i<=n;i++)
		cin>>a[i],pos[a[i]]=i;
	for(int i=1;i<=n;i++)//对于每个a[i],存入能被a[i]整除的值的下标到vec[i]
		for(int j=a[i];j<=n;j+=a[i])//以右端点下标存储
			vec[max(i,pos[j])].push_back(min(i,pos[j]));
	sort(a.begin()+1,a.end());
	vector<int>ans(m,0);
	vector<ques>rec;
	for(int i=0,l,r;i<m;i++)
	{
		cin>>l>>r;
		rec.push_back(ques(l,r,i));
	}
	sort(rec.begin(),rec.end(),[](const ques &x,const ques &y){
		return x.r<y.r;
	});//右边界小的优先处理
	int p=1;
	bit.init(n+1);
	for(ques &i:rec)
	{
		while(p<=i.r)
		{//限制右端点
			for(int &l:vec[p])
				bit.radd(l,l,1);
			p++;
		}
	//	fprintf(stderr,"[%d,%d] = %lld - %lld\n",i.l,i.r,bit.query(i.r),bit.query(i.l-1));
		ans[i.id]=bit.query(i.r)-bit.query(i.l-1);
	}
	for(auto &i:ans)
		cout<<i<<'\n';
	return 0;
}
/*
 * 数组区间[l,r]有多少对能整除的
 */
