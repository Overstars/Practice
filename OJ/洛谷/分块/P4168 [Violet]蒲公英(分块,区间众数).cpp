#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read()//快读挂
{
    int x=0,f=1;//改动x%mod即可在读入时取模
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return x*f;
}
inline void out(register int x)
{
    if(x>=10)
		out(x/10);
    putchar(x%10+'0');
}
const int maxn=40005,lim=205,inf=0x3f3f3f3f;
int a[maxn],c[maxn],id=0,f[lim][lim];
int siz,num,belong[maxn];
struct block
{
	int l,r;
} b[lim];
map<int,int> QAQ;
vector<int> pos[maxn];//存储种类下标
int val[maxn];//QAQ的反函数
void debug(int n)
{
	printf("siz=%d,num=%d\n",siz,num);
	for(int i=1;i<=num;i++)
	{
		for(int j=i;j<=num;j++)
		{
			printf("f[%d][%d]=%d\n",i,j,f[i][j]);
		}
	}
}
void build(int n)
{
	siz=sqrt(n);
	num=n/siz;
	if(n%siz)
		num++;
	for(int i=1;i<=num;i++)
		b[i].l=(i-1)*siz+1,b[i].r=i*siz;
	b[num].r=n;//特殊处理
	for(int i=1;i<=n;i++)
		belong[i]=(i-1)/siz+1;
	//伪离散化
//	for(int i=1;i<=n;i++)
//		pos[i].push_back(-1);
	for(int i=1;i<=n;i++)
	{
		if(QAQ[a[i]]==0)
		{
			QAQ[a[i]]=++id;//新编号
			val[id]=a[i];
//			printf("val[%d]=%d,QAQ[%d]=%d\n",id,val[id],a[i],QAQ[i]);
		}
		a[i]=QAQ[a[i]];
		pos[a[i]].push_back(i);//记录出现位置,自动升序
	}
	//暴力预处理区间众数,f[i][j]表示i块到j块*众数编号*
	for(int i=1;i<=belong[n];i++)
	{
		memset(c,0,sizeof(c));
		int maxc=0,ans=0;
		for(int j=b[i].l;j<=n;j++)//枚举起点,一直处理到最后
		{
			c[a[j]]++;//统计数量
			if(c[a[j]]>maxc||c[a[j]]==maxc&&val[a[j]]<val[ans])
			{//更新当前众数答案
				maxc=c[a[j]];//更新众数数量
				ans=a[j];
			}
			f[i][belong[j]]=ans;
//			printf("a[%d]=%d,c=%d\n",j,a[j],c[a[j]]);
//			printf("f[%d][%d]=%d\n",i,belong[j],f[i][belong[j]]);
		}
	}
//	debug(n);
}
int querynum(int l,int r,int x)//查询[l,r]内编号为x的数量
{
	return upper_bound(pos[x].begin(),pos[x].end(),r)-lower_bound(pos[x].begin(),pos[x].end(),l);
}
int query(int l,int r)
{
	int ans=0,maxc=0;
	ans=f[belong[l]+1][belong[r]-1];//提溜出来中间的整块众数
	maxc=querynum(l,r,ans);
	if(belong[l]==belong[r])
	{
//		memset(c,0,sizeof(c));
		for(int i=l;i<=r;i++)
		{
			int num=querynum(l,r,a[i]);//查询a[i]在[l,r]上的个数
			if(num>maxc||num==maxc&&val[a[i]]<val[ans])
			{
//				printf("ans=%d,maxc=%d\n",ans,maxc);
				ans=a[i];
				maxc=num;
			}
		}
		return val[ans];
	}
	//不在同一块
//	printf("ans=%d,maxc=%d\n",ans,maxc);
	for(int i=l;i<=b[belong[l]].r;i++)//枚举左面散装
	{
		int num=querynum(l,r,a[i]);//查询a[i]在[l,r]上的个数
		if(num>maxc||num==maxc&&val[a[i]]<val[ans])
		{
//			printf("ans=%d,maxc=%d\n",ans,maxc);
			ans=a[i];
			maxc=num;
		}
	}
	for(int i=b[belong[r]].l;i<=r;i++)
	{
		int num=querynum(l,r,a[i]);//查询a[i]在[l,r]上的个数
		if(num>maxc||num==maxc&&val[a[i]]<val[ans])
		{
			ans=a[i];
			maxc=num;
		}
//		printf("a[%d]=%d,ans=%d,maxc=%d\n",i,a[i],ans,maxc);
	}
//	printf("ans=%d,maxc=%d\n",ans,maxc);
	return val[ans];//返回实际种类
}
signed main()
{
//	freopen("P4168.in","r",stdin);
	int n,m,ans=0;//n株蒲公英,m次询问
//	scanf("%d%d",&n,&m);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	build(n);
	while(m--)
	{
		int l0,r0,l,r;
//		scanf("%d%d",&l0,&r0);
		l0=read(),r0=read();
		l=(l0+ans-1)%n+1;
		r=(r0+ans-1)%n+1;
		if(l>r)
			swap(l,r);
		ans=query(l,r);
		printf("%d\n",ans);
	}
	return 0;
}
