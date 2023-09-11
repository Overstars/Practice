#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,u,d,cnt;
	while(cin>>n>>u>>d&&n){
		cnt=0;
		while(n>u){
			n-=u-d;
			cnt+=2;
//			printf("n=%d,u=%d,d=%d\n",n,u,d);
		}
		cout<<cnt+1<<endl;
	}
	return 0;
}
