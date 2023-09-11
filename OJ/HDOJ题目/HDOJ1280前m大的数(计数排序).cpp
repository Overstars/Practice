#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
const int inf=0x3f3f3f3f;
int a[5005],b[10005];//将两个数的和作为下标记录
int main()
{
	int n,m;
	while(cin>>n>>m){
		memset(b,0,sizeof(b));
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
					b[a[i]+a[j]]++;
		for(int i=10001;m;)
		{
			while(b[i]&&m){
				printf("%d",i);
				b[i]--;
				m--;
				if(m==0)
					printf("\n");
				else
					printf(" ");
			}
			i--;
		}
	}
	return 0;
}
