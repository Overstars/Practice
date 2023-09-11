//#pragma G++ optimize("O2")
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<climits>
#include<cmath>
#include<iomanip>//控制输出,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<map>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int maxn=1005;
int w[maxn][maxn];//二分图间的权值
int lx[maxn],ly[maxn];
int linker[maxn];//B图匹配到的A图节点
int slack[maxn];
bool visy[maxn];//记录每一轮B图匹配过
int pre[maxn];
void bfs(int k,int n)
{
    int x,y=0,yy=0,delta;
    memset(pre,0,sizeof(pre));
    for(int i=1;i<=n;i++)
		slack[i]=INF;
    linker[y]=k;
    while(1)
	{
        x=linker[y];
        delta=INF;
        visy[y]=true;
        for(int i=1;i<=n;i++)
		{
            if(!visy[i])
            {
                if(slack[i]>lx[x]+ly[i]-w[x][i])
                {
                    slack[i]=lx[x]+ly[i]-w[x][i];
                    pre[i]=y;
                }
                if(slack[i]<delta)
					delta=slack[i],yy=i;
            }
        }
        for(int i=0;i<=n;i++)
        {
            if( visy[i] )
				lx[linker[i]]-=delta,ly[i]+=delta;
            else
				slack[i]-=delta;
        }
        y=yy;
        if(linker[y]==-1)
			break;
    }
    while(y)
		linker[y]=linker[pre[y]],y=pre[y];
}
int KM(int n)
{
    memset(lx,0,sizeof(lx));
    memset(ly,0,sizeof(ly));
    memset(linker,-1,sizeof(linker));
    for(int i=1;i<=n;i++)
	{
        memset(visy,false,sizeof(visy));
        bfs(i,n);
    }
    int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(linker[i]!=-1)
			ans+=w[linker[i]][i];
	}
	return ans;
}
struct student
{
	int h;
	char sex;
	string music,sport;
	student()
	{
		h=0;
		sex='\0';
		music=sport="";
	}
	student(int h,char s,const string &mu,const string &sp):
		h(h),sex(s),music(mu),sport(sp){}
};
vector<student> Man,Woman;
inline bool judge(int x,int y)//若四条都不符合,为真
{
	if(abs(Man[x].h-Woman[y].h)>40)//身高差大于40
		return 0;
	if(Man[x].sex==Woman[y].sex)//性别相同
		return 0;
	if(Man[x].music.compare(Woman[y].music))//不相同
		return 0;
	if(!Man[x].sport.compare(Woman[y].sport))//相同
		return 0;
	return 1;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
//	freopen("UVA12083.in","r",stdin);
//	freopen("out.ans","w",stdout);
	int t,n;
	int h;
	char sex;
	string mus,spo="213";
	cin>>t;
	while(t--)
	{
		cin>>n;
		int man=0,woman=0;
		Man.clear();
		Man.push_back(student(0,'M',spo,spo));
		Woman.clear();
		Woman.push_back(student(0,'F',spo,spo));
		for(int i=1;i<=n;i++)
		{
			cin>>h>>sex>>mus>>spo;
			if(sex=='M')
				Man.push_back(student(h,sex,mus,spo)),man++;
			else
				Woman.push_back(student(h,sex,mus,spo)),woman++;
		}
		memset(w,0,sizeof(w));
		for(int i=1;i<=man;i++)
			for(int j=1;j<=woman;j++)
			{
				if(judge(i,j))//有恋爱可能的人连边,边上的两人只能去一人
				{
					w[i][j]=1;
//					w[j][i]=1;
				}
			}
		cout<<n-KM(n)<<endl;
	}
	return 0;
}
/*
老师要带学生们出游，并尽量防止学生早恋，一些规则表示两个人早恋的可能性很小
1.身高相差40厘米以上
2.同性
3.喜欢的音乐风格不同
4.喜欢的运动是相同(防止不同引起旅行中的争吵)
参加旅行其中的任何两人必须至少满足上面的一条。
输出可参加旅行的最大人数。

输入：
第一行，表示测试数据组数T
每组数据的第一行由一个整数n (n≤500)
接下来的n行，每行有四个由空格隔开的数据
*整数h：以cm为单位的身高
*字符：“ F”代表女 “ M”代表男
*字符串：喜欢的音乐风格
*字符串：喜欢的运动

输出：
对每组数据，输出

思路：最大独立集=n-最大匹配数
拆点，在所有条件都不符合的两个同学建图
*/
