#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int isprime(int x);
void dfs(int x);
int flag[20],ans[21]={0,1};//排列1~n
int n;
int main()
{
	int cnt=0;
	while(cin>>n){
		memset(flag,0,sizeof(flag));
		printf("Case %d:\n",++cnt);
		dfs(2);
		putchar('\n');
	}
	return 0;
}
void dfs(int x)//为逆时针开始第x个位置求解
{
	if(x==n+1&&isprime(ans[n]+ans[1])){//n个数全部符合,到达叶子节点,输出并返回父节点
		printf("%d",ans[1]);
		int i;
		for(i=2;i<=n;i++)
			printf(" %d",ans[i]);
		putchar('\n');
	}
	else{
		int i;
		for(i=2;i<=n;i++){
			if(!flag[i]&&isprime(ans[x-1]+i)){//尝试搜索剩下的数可行排列,若可用的数无法与上一个组成质数则结束该分支搜索
				ans[x]=i;
				flag[i]=1;//标记该节点用到的数值，防止子节点使用该数
				dfs(x+1);//搜索存在的子节点
				flag[i]=0;//该分支搜索完,返回父节点前将标记清除
			}
		}
	}
	return;
}
int isprime(int x)
{
	if(x==0||x==1)
		return 0;
	int i;
	for(i=2;i<=sqrt(x);i++)
		if(x%i==0)
			return 0;
	return 1;
}
