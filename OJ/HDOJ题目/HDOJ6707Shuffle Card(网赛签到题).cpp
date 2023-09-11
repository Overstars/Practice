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
bool a[1000005];
int main()
{
	int n,m,i,temp,cnt=0;
	cin>>n>>m;
	for(i=0;i<n;i++){
		scanf("%d",&temp);
//		a[temp]=0;
	}
	stack<int> XOX;
	for(i=0;i<m;i++){
		scanf("%d",&temp);
		XOX.push(temp);
	}
	while(!XOX.empty()){
		temp=XOX.top();
		XOX.pop();
		if(a[temp]==0){
			cnt++;
			a[temp]=1;
//			if(cnt<n)
				printf("%d ",temp);
//			else
//				printf("%d",temp);
		}
	}
    for(i=1;i<=n;i++)
		if(a[i]==0){
			cnt++;
//			if(cnt<n)
				printf("%d ",i);
//			else
//				printf("%d",i);
		}
	return 0;
}
