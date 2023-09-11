#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[500005];
int main()
{
    int l,m,n,i;//输出可以过岸的最短跳跃能力
    while(cin>>l>>n>>m){//河宽l,n块石头,最多跳m次
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		a[n+1]=l;
		sort(a,a+n+2);
		int maxn=0;
		for(i=1;i<=n+1;i++)
			maxn=max(maxn,a[i]-a[i-1]);
		int left=maxn,right=l,mid;//mid为检验的步长
		while(left<=right){
			int pos=0,cnt=0;//从岸出发,跳的次数
			mid=(left+right)/2;
			for(i=1;i<=n;i++)
				if(a[i]-a[pos]<=mid&&a[i+1]-a[pos]>mid)
				{
					pos=i;
					cnt++;//跳一步
				}
			cnt++;//跳到对岸
			if(cnt<=m)//最低步长大了,没有充分利用步数
				right=mid-1;
			else//所需步数不够,加大步长
				left=mid+1;
		}
		printf("%d\n",left);
    }
    return 0;
}
