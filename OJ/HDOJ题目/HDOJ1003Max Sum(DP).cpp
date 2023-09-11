#include<iostream>
#include<cstdio>
using namespace std;
const int INF=0x3f3f3f3f;
int dp[100005];
int main()
{
	int t,n,head,tail,i,j,sum,maxi,newstart;
	cin>>t;
	for(i=1;i<=t;i++){
		if(i>1)
			cout<<endl;
		cin>>n;
		head=newstart=1;
		maxi=-INF;
		sum=0;
		for(j=1;j<=n;j++){
			scanf("%d",&dp[j]);
			sum+=dp[j];
			if(sum>maxi){
				maxi=sum;
				head=newstart;
				tail=j;
			}
			if(sum<0){
				sum=0;
				newstart=j+1;
			}
		}
		printf("Case %d:\n%d %d %d\n",i,maxi,head,tail);
	}
	return 0;
}
