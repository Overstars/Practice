#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
const int maxm=1005;
int num,siz,belong[maxn];//分块数量和大小,表示i属于哪一块
bool d[maxn];
struct block
{
	int l,r,light;
	bool lazy;
	block()
	{
		l=r=light=0;//第i块有多少灯在亮
		lazy=0;//0表示还未反转
	}
} bl[maxm];
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
void build(int n)
{
	siz=sqrt(n);
	num=n/siz;
	if(n%siz)
		num++;
	for(int i=1;i<=num;i++)
		bl[i].l=(i-1)*siz+1,bl[i].r=i*siz;
	bl[num].r=n;//特殊处理
	for(int i=1;i<=n;i++)
		belong[i]=(i-1)/siz+1;
}
void debug(int n)
{
	printf("lazy:\t");
	for(int i=1;i<=n;i++)
		printf("%4d",bl[belong[i]].lazy);
	printf("\n");
	printf("d:\t");
	for(int i=1;i<=n;i++)
		printf("%4d",d[i]);
	printf("\nans:\t");
	for(int i=1;i<=n;i++)
		printf("%4d",bl[belong[i]].light);
	printf("\n****\n");
}
void modify(int l,int r)
{
	if(belong[l]==belong[r])//在同一块内
	{
		for(int i=l;i<=r;i++)
		{//有r-l+1盏灯,暴力修改
			if(d[i])
			{
				if(!bl[belong[i]].lazy)//灯在亮且本块未标记修改
					bl[belong[i]].light--;
				else
					bl[belong[i]].light++;
			}
			else{
//				printf("???");
				if(!bl[belong[i]].lazy)//灯灭且区间未标记修改
					bl[belong[i]].light++;
				else
					bl[belong[i]].light--;//灯灭且区间标记已修改
			}
			d[i]^=1;//散装灯的状态还是要修改的...
		}
//		debug(5);
		return;
	}
	//否则不在同一块
	for(int i=l;i<=bl[belong[l]].r;i++)
	{
		if(d[i])
		{
			if(!bl[belong[i]].lazy)//灯在亮且本块未标记修改
				bl[belong[i]].light--;
			else
				bl[belong[i]].light++;
		}
		else{
			if(!bl[belong[i]].lazy)//灯灭且区间未标记修改
				bl[belong[i]].light++;
			else
				bl[belong[i]].light--;//灯灭且区间标记已修改
		}
		d[i]^=1;
	}
	for(int i=belong[l]+1;i<belong[r];i++)//整块的修改lazy标记
	{
		bl[i].lazy^=1;
		bl[i].light=siz-bl[i].light;
	}
	for(int i=bl[belong[r]].l;i<=r;i++)
	{
		if(d[i])
		{
			if(!bl[belong[i]].lazy)//灯在亮且本块未标记修改
				bl[belong[i]].light--;
			else
				bl[belong[i]].light++;
		}
		else{
			if(!bl[belong[i]].lazy)//灯灭且区间未标记修改
				bl[belong[i]].light++;
			else
				bl[belong[i]].light--;//灯灭且区间标记已修改
		}
		d[i]^=1;
	}
}
int query(int l,int r)
{
	if(belong[l]==belong[r])//在同一块内
	{
		int cnt=0;
		for(int i=l;i<=r;i++)
			if(d[i]^bl[belong[i]].lazy)
				cnt++;
		return cnt;
	}
	int ans=0;//不在同一块
	for(int i=l;i<=bl[belong[l]].r;i++)
		if(d[i]^bl[belong[i]].lazy)
			ans++;
	for(int i=belong[l]+1;i<belong[r];i++)
		ans+=bl[i].light;
	for(int i=bl[belong[r]].l;i<=r;i++)
		if(d[i]^bl[belong[i]].lazy)
			ans++;
	return ans;
}
int main()
{
	int n,m,ope,a,b;
	n=read(),m=read();
	build(n);
	while(m--)
	{
		ope=read(),a=read(),b=read();
		if(ope==0)
			modify(a,b);
		else
			out(query(a,b)),putchar('\n');
	}
	return 0;
}
