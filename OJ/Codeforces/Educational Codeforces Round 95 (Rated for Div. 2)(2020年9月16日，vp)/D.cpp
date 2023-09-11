//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
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
int p[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,q,op,x;
	cin>>n>>q;
	multiset<int>gap,pile;
	multiset<int>::iterator it,it1,it2;
	for(int i=1;i<=n;i++)//扫成两堆
		cin>>p[i],pile.insert(p[i]);
	sort(p+1,p+n+1);
	int l,r,w=0;
	l=p[1],r=p[n];
	for(int i=2;i<=n;i++)
		gap.insert(p[i]-p[i-1]);
	if(n==1)
		cout<<0<<endl;
	else
		cout<<r-l-*gap.end()<<endl;
	while(q--)
	{
		cin>>op>>x;//0移走,1添加
		if(op==0)//移走
		{
			it=pile.lower_bound(x);
			if(it==pile.begin())//最左
			{
				pile.erase(it);
				if(!pile.empty())
				{
					l=*pile.begin();//更新左端点
					it2=gap.lower_bound(l-x);
					gap.erase(it2);//删去缝隙
				}
				else
					l=r=w=0;
			}
			else if(it==pile.end())//最右
			{
				pile.erase(it);
				if(!pile.empty())
				{
					r=*pile.end();//更新右端点
					it2=gap.lower_bound(x-r);
					gap.erase(it2);//删去缝隙
				}
				else
					l=r=w=0;
			}
			else{//在中间,不影响l,r
				int nex=*pile.upper_bound(x),pre;
				it--;
				pre=*it;
				pile.erase(x);
//				printf("x=%d,pre=%d,nex=%d\n",x,pre,nex);
				int n1=x-pre,n2=nex-x;
				gap.insert(nex-pre);
				it1=gap.lower_bound(n1);
				gap.erase(it1);
				it1=gap.lower_bound(n2);
				gap.erase(it1);
			}
		}
		else{//添加
			if(pile.empty())
				pile.insert(x),l=r=x;
			else if(pile.size()==1)
			{
				l=min(l,x);
				r=max(r,x);
				pile.insert(x);
				gap.insert(r-l);
			}
			else
			{
				it=pile.lower_bound(x);
				if(it==pile.begin())
				{
					gap.insert(l-x);
					l=x;
				}
				else if(it==pile.end())
				{
					gap.insert(x-r);
					r=x;
				}
				else{
					int nex=*it;
					it--;
					int pre=*it;
//					printf("x=%d,pre=%d,nex=%d\n",x,pre,nex);
//					cout<<"!!!"<<*gap.lower_bound(nex-pre)<<endl;
					gap.erase(gap.lower_bound(nex-pre));
					gap.insert(nex-x);
					gap.insert(x-pre);
				}
				pile.insert(x);
			}
		}
		if(pile.size()==1||pile.empty())
			w=0;
		else
			w=*gap.rbegin();
		printf("l,r,w=%d,%d,%d\n",l,r,w);
//		cout<<"wtf=";
//		for(auto &i:pile)
//			cout<<i<<' ';
//		cout<<endl;
		cout<<r-l-w<<endl;
	}
	return 0;
}
/*
 *把垃圾扫成两堆
 *维护左右端点l,r和中间的最大缝隙w
 *ans=r-l-w
 *可能要用multiset维护所有缝隙
 *添加和删除两种操作
 */

