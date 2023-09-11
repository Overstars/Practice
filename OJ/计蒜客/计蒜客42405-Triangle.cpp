//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
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
#define zero(x) (((x)>0?(x):-(x))<eps)
struct point
{
	double x,y;
	point(){}
	point(double a,double b):
		x(a),y(b){}
};
struct line{point a,b;};
//判三点共线
double xmult(point p1,point p2,point p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int dots_inline(point p1,point p2,point p3){
	return zero(xmult(p1,p2,p3));
}
//判点是否在线段上,包括端点
int dot_online_in(point p,line l){
	return zero(xmult(p,l.a,l.b))&&(l.a.x-p.x)*(l.b.x-p.x)<eps&&(l.a.y-p.y)*(l.b.y-p.y)<eps;
}
int dot_online_in(point p,point l1,point l2){
	return zero(xmult(p,l1,l2))&&(l1.x-p.x)*(l2.x-p.x)<eps&&(l1.y-p.y)*(l2.y-p.y)<eps;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,x[3],y[3],px,py;
	cin>>t;
	while(t--)
	{
		vector<point>rec;
		for(int i=0;i<3;i++)
		{
			cin>>x[i]>>y[i];
			rec.push_back(point(x[i],y[i]));
		}
		point p;
		cin>>p.x>>p.y;
		bool ok=0;
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				if(i!=j)
					ok|=dot_online_in(p,rec[i],rec[j]);
		if(!ok)
		{
			cout<<-1<<endl;
			continue;
		}
	}
	return 0;
}


