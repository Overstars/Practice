//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=1025,inf=0x3f3f3f3f,mod=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int MAXN = 100000;
const double EPS = 1e-8;
// 带误差比较
inline bool dcmp(double x, double y = 0)
{
    return fabs(x - y) <= EPS;
}
/*
 * 向量（Vector）或点
 * 使用原点到一个点 (x, y) 的有向线段表示向量
 * 从点 A 到点 B 的向量表示为 A - B
 */
typedef struct Vec
{
    double x, y;
    Vec(double x = 0, double y = 0) : x(x), y(y) {}
    // 相加
    Vec operator+(const Vec &v) const
    {
        return Vec(x + v.x, y + v.y);
    }
    // 相减
    Vec operator-(const Vec &v) const
    {
        return Vec(x - v.x, y - v.y);
    }
    // 数乘（伸长、缩短）
    Vec operator*(double d) const
    {
        return Vec(x * d, y * d);
    }
    Vec operator/(const double d) const
    {
        return Vec(x / d, y / d);
    }
    // 范数，用来比较长度，等于长度的平方
    double norm() const
    {
        return x * x + y * y;
    }
} Pt;
// 点乘
double dot(const Vec &a, const Vec &b)
{
    return a.x * b.x + a.y * b.y;
}
// 叉乘
double cross(const Vec &a, const Vec &b)
{
    return a.x * b.y - a.y * b.x;
}
// 线段（Segment），用两个点表示

struct Seg
{
    Pt a, b;
    Seg(){}
    Seg(const Pt &a, const Pt &b) : a(a), b(b) {}
    // 线段包含点（点在线段上）
    double get_distance(Pt p, Pt A, Pt B)
    {
		Pt Ap, Ab, Bp;
		Ap.x = p.x - A.x, Ap.y = p.y - A.y;
		Ab.x = B.x - A.x, Ab.y = B.y - A.y;
		Bp.x = p.x - B.x, Bp.y = p.y - B.y;
		double r = (Ap.x*Ab.x + Ap.y*Ab.y)*1.0 / (Ab.x*Ab.x + Ab.y*Ab.y);

		if (r <= 0)return sqrt(Ap.x*Ap.x*1.0 + Ap.y*Ap.y);
		if (r >= 1)return sqrt(Bp.x*Bp.x*1.0+Bp.y*Bp.y);
		double px = A.x + Ab.x*r;
		double py = A.y + Ab.y*r;
		return sqrt((p.x-px)*(p.x-px)+(p.y-py)*(p.y-py));
	}
	double dis(const Pt &p)
	{
		return get_distance(p,a,b);
	}
    bool include(const Pt &p)
    {
        // PA × PB = 0：PA 与 PB 共线，即点在线段所在的直线上
        // PA · PB = 0：PA 与 PB 方向不同（A 和 B 分别在 P 的两边），如果 PA · PB = 0 则 P = A 或 P = B
        return dcmp(cross(a - p, b - p)) && dot(a - p, b - p) <= 0;
    }
};
// 直线，用两个点表示
struct Line
{
    Pt a, b;
    Line() {} // 提供一个不需要参数的构造函数
    Line(const Pt &a, const Pt &b) : a(a), b(b) {}
    bool include(const Pt &p) const
    {//点在线段上
        return dcmp(cross(a - p, b - p));
    }
    // 两直线关系（交点个数）
    // 0 表示平行（无交点）
    // 1 表示相交（一个交点）
    // -1 表示重合（无数个交点）
    static int relation(const Line &a, const Line &b)
    {
        if (a.include(b.a) && a.include(b.b)) return -1;
        else if (dcmp(cross(a.b - a.a, b.b - b.a))) return 0;
        else return 1;
    }
};
int relation(const Line &a, const Line &b)
{
	if (a.include(b.a) && a.include(b.b)) return -1;
	else if (dcmp(cross(a.b - a.a, b.b - b.a))) return 0;
	else return 1;
}
Pt intersect(const Line &a, const Line &b)
{// 求两直线交点（需要保证两直线有交点）
	double s1 = cross(b.a - a.a, b.b - a.a), s2 = cross(b.b - a.b, b.a - a.b);
	return a.a + (a.b - a.a) * s1 / (s1 + s2);
}
Pt pp[maxn];
vector<Line> lin[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,h,k;
	double xs,ys,xt,yt,x,y;
	cin>>n>>m;
	cin>>xs>>ys>>xt>>yt;
	Pt ta=Pt(xs,ys),tb=Pt(xt,yt);
	Line st=Line(ta,tb);
	Seg stt=Seg(ta,tb);
	for(int i=1;i<=n;i++)
		cin>>pp[i].x>>pp[i].y;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			Line now=Line(pp[i],pp[j]);
			lin[i].push_back(now);
			lin[j].push_back(now);
		}
	}
	while(m--)
	{
		cin>>h>>k;
		vector<Pt> rec;
		for(Line &i:lin[h])
		{
			if(relation(st,i)==1)
			{
				Pt tmp=intersect(st,i);
				if(stt.dis(tmp)<EPS)
					rec.push_back(tmp);
			}
		}
		if(k>rec.size())
		{
			cout<<-1<<endl;
		}
		else{
			sort(rec.begin(),rec.end(),[xs,ys](const Pt &a,const Pt &b){
					return (a.x-xs)*(a.x-xs)+(a.y-ys)*(a.y-ys)<(b.x-xs)*(b.x-xs)+(b.y-ys)*(b.y-ys);
				});
//			for(Pt &i:rec)
//				cout<<"wtf"<<i.x<<' '<<i.y<<endl;
			cout<<setiosflags(ios::fixed)<<setprecision(7)<<rec[k-1].x<<' '<<rec[k-1].y<<endl;
		}
	}
	return 0;
}
/*
 * 2021-04-13-16.55.55
 * 第h个风车改变k次顺序时观察者所在的坐标
*/

