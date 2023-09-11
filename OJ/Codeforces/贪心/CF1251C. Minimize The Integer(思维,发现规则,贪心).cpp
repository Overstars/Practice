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
//#define lowbit(x) ((x) & -(x))
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=300005;
//#define DEBUG
/*
 *任何一个字符可以自由左右移动直到遇见属性不同的字符
 *所以任何字符不会跨越自己的属性
 *即同性字符相对位置不会改变
 *将所有小的字符往前移
*/
char str[maxn]={'0','0','8'};
bool rec[maxn];
inline bool jud(const int & x,const int &y)
{
	return ((int)str[x]&1)^((int)str[y]&1);//相同为真
}
inline bool odd(const char &ch)
{
	return ch&1;
}
inline void run(int x,int y)//将x移动到y
{
	if(y<x)
		swap(x,y);
	char tem=str[y];
//	swap(str[x],str[y]);
//	swap(rec[x],rec[y]);
	for(int i=y;i>x;i--)
	{
		str[i]=str[i-1];
	}
	str[x]=tem;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",str+1);
		int len=strlen(str+1);
//		memset(rec,0,sizeof(rec));
//		for(int i=1;i<=len;i++)
//			if(s[i]&1)
//				rec[i]=1;
//		for(int i=1;i<=len;i++)//从前向后找到可交换的最小的
//		{
//			char val=s[i];
//			int loc=i;
//			bool flag=0;
//			for(int j=i+1;j<=len;j++)
//			{
//				if(jud(i,j))//属性不同
//				{
//					if(s[j]<=val)
//					{
//						flag=1;
//						val=s[j];
//						loc=j;
//					}
//					break;//碰到了就要跳出去
//				}
//			}
//			if(flag)
//			{
////				printf("s[%d]=%c swap s[%d]=%c\n",i,s[i],loc,s[loc]);
//				run(i,loc);
//			}
////			printf("%d:%s\n",i,s+1);
//		}
//		printf("%s\n",s+1);
		string s[2];
		for(int i=1;i<=len;i++)
		{
			if(!odd(str[i]))
				s[0]+=str[i];//偶数
			else
				s[1]+=str[i];
		}
		int i=0,j=0;
		while((i<s[0].size())||(j<s[1].size()))
		{
			if(i==s[0].size())
			{
				while(j<s[1].size())
					cout<<s[1][j++];
			}
			if(j==s[1].size())
			{
				while(i<s[0].size())
					cout<<s[0][i++];
			}
			if(i<s[0].size()&&j<s[1].size())
				if(s[0][i]<s[1][j])
					cout<<s[0][i++];
				else
					cout<<s[1][j++];
		}
		cout<<endl;
	}
	return 0;
}
