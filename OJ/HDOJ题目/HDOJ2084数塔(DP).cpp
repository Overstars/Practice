#include<cstdio>
#include<iostream>
using namespace std;
int tower[100][100];
int dp[100][100];
int maxi(int a,int b);
int main()
{
	int c;
	cin>>c;
	while(c--){
		int n,i,j;
		cin>>n;
		for(i=0;i<n;i++)
			for(j=0;j<=i;j++)
				cin>>tower[i][j];
		dp[0][0]=tower[0][0];
		for(i=1;i<n;i++)
			for(j=0;j<=i;j++){
				if(j==0)
					dp[i][j]=dp[i-1][j]+tower[i][j];
				else if(i==j)
					dp[i][j]=dp[i-1][j-1]+tower[i][j];
				else
					dp[i][j]=maxi(dp[i-1][j]+tower[i][j],dp[i-1][j-1]+tower[i][j]);

			}
		int m=dp[n-1][0];
		for(i=1;i<n;i++)
			if(m<dp[n-1][i])
				m=dp[n-1][i];
		cout<<m<<endl;
	}
	return 0;
}
int maxi(int a,int b)
{
	return (a>b)?a:b;
}
