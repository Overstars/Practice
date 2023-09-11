#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
//struct node
//{
//	int x,val;
//	struct node(int a,int b):
//		a(a),b(b){}
//	bool operator<(const node& tmp) const{
//        if(this->x < tmp.x)
//            return true;//小的在前
//        return false;
//    }
//};
//set<node>st;
//set<node>::iterator it;
map<int,int>mp;
set<int>st;//维护范围内非0数
map<int,int>::iterator it;
set<int>::iterator it2;
void add(int x,int c)
{
	bool flag=1;
	it2=st.lower_bound(x-30);
	for(set<int>::iterator it3=it2;it3!=st.end();it3++)
	{
		if(*it3<=x+30)
			return;
		else
			break;
	}
	if(mp[x]+c==0)
	{
		mp.erase(x);
		st.erase(x);
	}
	st.insert(x);
	mp[x]+=c;
}
int sub()
{
	if(st.empty())
		return 0;
	it=mp.begin();
	int ret=it->second;
	st.erase(st.begin());
	mp.erase(mp.begin());
	return ret;
}
int query(int x)
{
	it2=st.find(x);
	if(it2==st.end())//不在
		return 0;
	return mp[x];
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
	int n,t,c;
	scanf("%d",&n);
	while(n--)
	{
		char ch='?';
		scanf("%d%c",&t,&ch);
		if(ch==' ')
		{
			scanf("%d",&c);
			add(t,c);//a[t]+=c
			continue;
		}
		if(t==-1)
		{
			if(st.empty())
				printf("skipped\n");
			else{
				printf("%d\n",sub());
			}
		}
		else
			printf("%d\n",query(t));
	}
	return 0;
}


