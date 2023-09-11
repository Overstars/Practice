#include<iostream>
#include<cstdio>
using namespace std;
int a[1000005],b[10005],nex[10005];
void getnext(int m)
{
	nex[0]=0;
	int i,j;
	for(i=1,j=0;i<m;i++){
		j=nex[i-1];
		while(j>0&&b[i]!=b[j])
			j=nex[j-1];
		if(b[i]==b[j])
			j++;
		nex[i]=j;
	}
}
int kmp(int n,int m)
{
	int cmp=0;
	for(int i=0;i<n;i++)
	{
		while(a[i]!=b[cmp]&&cmp>0)
			cmp=nex[cmp-1];
		if(a[i]==b[cmp])
			cmp++;
		if(cmp==m){
			return i-m+2;
		}
	}
	return -1;
}
int main()
{
	int t,i,j,n,m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<m;i++)
			scanf("%d",&b[i]);
		getnext(m);
		cout<<kmp(n,m)<<endl;
	}
	return 0;
}
