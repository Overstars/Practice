#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[2005],b[2005],c[2005];//第i秒有多少车在等
int main()
{
	int n,m,i,cnt,tem,maxi,ma;
	while(cin>>n>>m){
		ma=maxi=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(i=0;i<n;i++)
		{
			scanf("%d",&tem);
			a[tem]++;
			ma=max(ma,tem);
		}
		for(i=0;i<m;i++)
		{
			scanf("%d",&tem);
			b[tem]++;
			maxi=max(maxi,tem);
		}
		cnt=-1;
		while(1){
			cnt++;
			int flag=0;
			memset(c,0,sizeof(c));
			for(i=1;i<=maxi;i++){
				c[i+cnt]=b[i];//南北方向向后延cnt
			}
			for(i=1;i<=min(ma,maxi+cnt);i++)
				if(a[i]>0&&c[i]>0){
					flag=1;
					break;
				}
			if(flag==0)
				break;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
//			printf("\n^^^^^^^^^^^^^^^^\n");
//			printf("n=%d,m+cnt=%d\n",n,m+cnt);
//			for(i=1;i<1005;i++)
//			{
//				printf("a[%d]=%d ",i,a[i]);
//				printf("c[%d]=%d ",i,c[i]);
//			}
//			printf("\n^^^^^^^^^^^^^^^^\n");
