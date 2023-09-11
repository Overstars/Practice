#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f,mod=1000000007;
const double eps= 1e-8,pi=acos(-1);
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
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
	int type,id;
	double angle;
	node (int a,double b,int c):
		type(a),id(c),angle(fmod(b+2*pi,2*pi)){}
	bool operator <(const node &b)
	{
		if(abs(angle-b.angle)>eps)//角不相等
			return angle<b.angle;
		else
			return type<b.type;
	}
};
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n,d,c;
	cin>>t;
	while(t--)
	{
		cin>>n>>d;//数量n,有效半径d
		vector<node> v;
		for(int i=c=0;i<n;i++)
		{
			double x,y;
			cin>>x>>y;
			if(x*x+y*y<=d*d+eps)
				continue;//随便开一枪就能打中
			double a=atan2(y,x);//(x,y)弧度角
			double t=asin(d/sqrt(x*x+y*y));//确定角度范围
			v.push_back(node(0,a-t,c));//角度在[a-t,a+t]即可打中
			v.push_back(node(1,a+t,c++));
		}
		if(c==0)
		{//所有的点都能随便开一枪就打中
			cout<<1<<endl;
			continue;
		}
		sort(v.begin(),v.end());
		int ans=c;//当前至少开c枪
		for(int i=0;i<v.size();i++)
		{//枚举第一枪位置
			int cnt=0;
			vector<bool>vis(c,0);
			vector<int>rec;
			for(int k=0;k<v.size();k++)//贪心求开多少枪
			{//以i开始向后的k个元素为j
				int j=(i+k)%v.size();
				if(v[j].type==0)//进入点j区域
				{
					vis[v[j].id]=1;
					rec.push_back(v[j].id);
				}
				else if(vis[v[j].id])//j区域结束
				{//要离开该点范围了,必须开一枪,同时击中rec中所有元素
					cnt++;
					for(int l:rec)
						vis[l]=0;
					rec.clear();
				}
			}
			cnt+=rec.size();
			ans=min(ans,cnt);
		}
		cout<<ans<<endl;
	}
	return 0;
}


