#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[30005],flag[30005];
int main()
{
	int n,i,j;
	while(cin>>n){
		int cnt=0;
		memset(flag,0,sizeof(flag));
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++){
			int cur=a[i];
			if(flag[i])
				continue;
			else{
				flag[i]=1;
				cnt++;
			}
			for(j=i+1;j<n;j++){
				if(!flag[j]&&a[j]<=cur){
					flag[j]=1;
					cur=a[j];
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
