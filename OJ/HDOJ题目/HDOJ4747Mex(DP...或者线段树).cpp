#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>//控制输出,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
const int inf=0x3f3f3f3f;
//题解:https://blog.csdn.net/qq1965610770/article/details/80041940
//#define DEBUG
int a[200005],pos[200005],full[200005];//原序列
//pos[i]:i在a序列中出现的最后一个位置
//full[j]:遍历到i时,full[j]表示已经覆盖了0~j的区间[x,i]中x的最大值
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	int n;
	while(cin>>n&&n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		memset(pos,0,sizeof(pos));
		memset(full,0,sizeof(full));
		long long inc=0,ans=0;//第i轮:inc表示[1,i]~[i,i]的mec的和
		int last;//记录某个数上次出现的位置
		for(int i=1;i<=n;i++)
		{
			//根据上一轮inc推出这一轮inc
			if(a[i]<n)//大于等于n的数不会对当前答案造成影响
			{
				last=pos[a[i]];//a[i]上次出现的位置
				pos[a[i]]=i;//更新pos
				//操作区间(last,i],a[i]对于last之前的区间无影响
				for(int j=a[i];j<n;j++)//遍历会产生影响的数字a[i]~n,这些数的mex可能会发生变化
				{
					if(j)
						full[j]=min(full[j-1],pos[j]);//保证区间[full[j],i]已经出现了0~j
					else//pos[j]如何理解?
						full[0]=i;
					if(full[j]>last)//对last之前的数字无影响
						inc+=full[j]-last;//(last,full[j]]内的所有mex+1
					else
						break;
				}
			}
			ans+=inc;
		}
		cout<<ans<<endl;
	}
	return 0;
}
