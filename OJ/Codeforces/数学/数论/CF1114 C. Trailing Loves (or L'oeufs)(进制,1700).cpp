//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
#include<cstdlib>
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
char* itoa(int num,char* str,int radix)
{
	char index[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";//索引表
	unsigned unum;//存放要转换的整数的绝对值,转换的整数可能是负数
	int i=0,j,k;//i用来指示设置字符串相应位，转换之后i其实就是字符串的长度；转换后顺序是逆序的，有正负的情况，k用来指示调整顺序的开始位置;j用来指示调整顺序时的交换。
	//获取要转换的整数的绝对值
	if(radix==10&&num<0)//要转换成十进制数并且是负数
	{
		unum=(unsigned)-num;//将num的绝对值赋给unum
		str[i++]='-';//在字符串最前面设置为'-'号，并且索引加1
	}
	else unum=(unsigned)num;//若是num为正，直接赋值给unum
	//转换部分，注意转换后是逆序的
	do{
		str[i++]=index[unum%(unsigned)radix];//取unum的最后一位，并设置为str对应位，指示索引加1
		unum/=radix;//unum去掉最后一位
	}while(unum);//直至unum为0退出循环
	str[i]='\0';//在字符串最后添加'\0'字符，c语言字符串以'\0'结束。
	//将顺序调整过来
	if(str[0]=='-') k=1;//如果是负数，符号不用调整，从符号后面开始调整
	else k=0;//不是负数，全部都要调整
	char temp;//临时变量，交换两个值时用到
	for(j=k;j<=(i-1)/2;j++)//头尾一一对称交换，i其实就是字符串的长度，索引最大值比长度少1
	{
		temp=str[j];//头部赋值给临时变量
		str[j]=str[i-1+k-j];//尾部赋值给头部
		str[i-1+k-j]=temp;//将临时变量的值(其实就是之前的头部值)赋给尾部
	}
	return str;//返回转换后的字符串
}
char str[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
//	for(int i=1;i<=100;i++)
//	{
//		itoa(i,str,9);
//		cout<<i<<":"<<str<<endl;
//	}
	vector<ll>f;
	map<ll,int>need;
	ll n,b,tmp,ans=LLONG_MAX;
	cin>>n>>b;
	tmp=b;
	for(ll i=2;i*i<=tmp;i++)
		if(tmp%i==0)
		{
			f.push_back(i);
			while(tmp%i==0)
				tmp/=i,need[i]++;
		}
	if(tmp>1)
		f.push_back(tmp),need[tmp]++;
	for(ll &x:f)
	{
		ll have=0;//求出n!里x有多少个
		for(ll p=x,i=1;p<=n;p*=x,i++)
		{//
//			printf("???\n");
			have+=n/p;
			if(n/p<x)//可能是乘上后就越界了
				break;
		}
//		printf("%lld,have=%lld\n",x,have);
		ans=min(ans,have/need[x]);
	}
	cout<<ans<<endl;
	return 0;
}
/*
 *求n!在b进制下末尾的零的个数
 *可以发现是计算n!中b出现的次数
 *所以将b质因子分解,统计n!中每个质因子出现的次数,再除以所需次数
 *取最小值即可
 */

