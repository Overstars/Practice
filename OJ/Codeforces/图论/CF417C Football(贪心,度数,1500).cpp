#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
vector<int>ans[maxn];
int in[maxn],out[maxn];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	if(k>(n-1)/2)
	{
		puts("-1");
	}
	else{
		printf("%d\n",n*k);
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(out[i]<k)
				{
					printf("%d %d\n",i,j);
					out[i]++;
				}
				else if(out[j]<k)
				{
					printf("%d %d\n",j,i);
					out[j]++;
				}
			}
		}
	}
	return 0;
}
