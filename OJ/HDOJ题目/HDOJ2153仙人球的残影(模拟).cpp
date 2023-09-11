#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int i,j,arr[15][15],n,cnt;
	while(cin>>n&&n){
		cnt=1;
		memset(arr,0,sizeof(arr));
		for(i=0;i<n;i++)
			arr[0][i]=cnt++;
		for(i=1;i<n;i++)
			arr[i][n-1]=cnt++;
		for(i=1;i<n;i++)
			arr[n-1][n-1-i]=cnt++;
		for(i=1;i<n-1;i++)
			arr[n-1-i][0]=cnt++;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++){
				if(arr[i][j]==0)
					printf("   ");
				else
					printf("%3d",arr[i][j]);
				if(j==n-1)
					putchar('\n');
			}
	}
	return 0;
}
