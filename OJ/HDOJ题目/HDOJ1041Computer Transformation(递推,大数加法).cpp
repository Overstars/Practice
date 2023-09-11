#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char ans[1001][505];
int len[1001];//中间出现0会被截断
void solve()
{
	memset(ans,0,sizeof(ans));
	memset(len,0,sizeof(len));
	ans[0][0]=0,ans[1][0]=0;
	ans[2][0]=1,ans[3][0]=1;
	len[2]=len[3]=1;
	for(int i=4;i<1001;i++){
		len[i]=len[i-1];
		int cc=0,j;
		for(j=0;j<len[i];j++)
		{
			ans[i][j]=ans[i-1][j]+2*ans[i-2][j]+cc;
			cc=ans[i][j]/10;
			ans[i][j]%=10;
		}
		if(cc){
			ans[i][j]=cc;
			len[i]++;
		}
	}
}
int main()
{
	int n;
	solve();
	while(cin>>n){
		if(n==0||n==1)
			cout<<"0"<<endl;
		else{
			for(int i=len[n]-1;i>=0;i--)
				putchar(ans[n][i]+'0');
			putchar('\n');
		}
	}
	return 0;
}
