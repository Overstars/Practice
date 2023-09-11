#include<iostream>
#include<cstdio>
using namespace std;
long long n;
int flag;
void dfs(int step,long long x)
{
	if(flag||step>19)
		return;
	if(x%n==0&&x>0){
		flag=1;
		cout<<x<<endl;
		return;
	}
	dfs(step+1,x*10);
	dfs(step+1,x*10+1);
}
int main()
{
	while(cin>>n&&n){
		flag=0;
		dfs(1,1);
	}
	return 0;
}
