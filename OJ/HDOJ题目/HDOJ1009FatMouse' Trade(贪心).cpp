#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef struct st
{
	int con;
	int req;
	double aver;
} house;
bool cmp(house a,house b);
int main()
{
	int m,n;
	double ans;
	house arr[1005];
	while(cin>>m>>n&&m>=0&&n>=0){
		int i;
		ans=0;
		for(i=0;i<n;i++){
			cin>>arr[i].con>>arr[i].req;
			arr[i].aver=(double)arr[i].con/arr[i].req;
		}
		sort(arr,arr+n,cmp);
		for(i=0;i<n&&m>=0;i++){
			if(m>=arr[i].req){
				m-=arr[i].req;
				ans+=arr[i].con;
			}
			else{
				ans+=(double)m/arr[i].req*arr[i].con;
				m=0;
			}
		}
		printf("%.3lf\n",ans);
	}
	return 0;
}
bool cmp(house a,house b)
{
	return a.aver>b.aver;
}
