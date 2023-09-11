#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[1000005];
bool cmp(int i,int j)
{
	return (i<j);
}
int main()
{
	int n,i,temp;
	while(cin>>n){
		int loc=0,maxn=0;
		memset(a,0,sizeof(a));
		for(i=0;i<n;i++){
			scanf("%d",&temp);
			a[temp]++;
			if(a[temp]>maxn){
				maxn=a[temp];
				loc=temp;
			}
		}
		cout<<loc<<endl;
	}
	return 0;
}
