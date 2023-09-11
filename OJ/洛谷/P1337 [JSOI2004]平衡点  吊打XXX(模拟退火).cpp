#include<bits/stdc++.h>
using namespace std;
const double delta=0.996;
int n;
double sx,sy;
double ansx,ansy;//最优解坐标
double ans=1e18+10,temper;//全局最优解、温度
struct node
{
	double x,y,w;
} a[1005];
int read()//快读挂
{
    int x=0,f=1;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return x*f;
}
inline double evaluate(const double &x,const double &y)//评价函数
{
	double ret=0;
	for(register int i=1;i<=n;i++)
	{
		double dx=x-a[i].x,dy=y-a[i].y;
		ret+=(double)sqrt(dx*dx+dy*dy)*a[i].w;//使各方向力矩平衡
	}
//	printf("ret=%.2lf\n",ret);
	return ret;//一定不为负
}
void simulateAnneal()//模拟退火主过程
{
	double nowx=ansx,nowy=ansy;
	ans=evaluate(nowx,nowy);//f(x)
	for(temper=2e3+50;temper>1e-14;temper*=delta)//目标小一点就过了
	{
		double nexx=nowx+temper*(((rand()<<1)-RAND_MAX));//为什么不除以RAND_MAX?
		double nexy=nowy+temper*(((rand()<<1)-RAND_MAX));
//		printf("%.2lf,%.2lf\n",nexx,nexy);
		double now=evaluate(nexx,nexy);
		double diss=now-ans;//函数变动值delta
//		cout<<"diss="<<diss<<endl;
		if(diss<=0)//成功降低系统能量
		{
			nowx=nexx,nowy=nexy;
			ansx=nowx,ansy=nowy;
			ans=now;
//			printf("temper%.2lf:(%.2lf,%.2lf)\n",temper,ansx,ansy);
		}
		else if(exp(-diss/temper)*RAND_MAX>rand())//概率接受,跳出局部
		{
			nowx=nexx,nowy=nexy;
		}
	}
}
void ac(int ca)
{
	for(int i=1;i<=n;i++)
		sx+=a[i].x,sy+=a[i].y;
	ansx=sx/n,ansy=sy/n;
//	printf("n=%d,sx=%d,sy=%d\n",n,sx,sy);
//	printf("%.2lf %.2lf\n",ansx,ansy);
//	for(int i=1;i<=n;i++)
//		printf("%d %d %d\n",a[i].x,a[i].y,a[i].w);
//	system("pause");
	for(register int i=1;i<=ca;i++)
	{
		srand(rand());
		simulateAnneal();
	}
	for(register int i=0;i<rand();i++)
	{
		srand(rand());
		if(i>500)
			break;
	}
	srand(12364352);
	simulateAnneal();
	srand(100000007);
	simulateAnneal();
	srand(666666);
	simulateAnneal();
}
int main()
{
	srand(time(0));
	srand(rand());
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf%lf",&a[i].x,&a[i].y,&a[i].w);
	}//输出平衡时绳结的位置
	ac(15);
	printf("%.3lf %.3lf\n",ansx,ansy);
	return 0;
}
