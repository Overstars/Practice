#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
int city[1005];
int findpar(int a);
int join(int a,int b);
int main()
{
	int n,m,uni;
	while(cin>>n>>m&&n){
		uni=n;//集团个数
		int i,city1,city2;
		for(i=1;i<=n;i++)
			city[i]=i;
		for(i=0;i<m;i++){//m条道路
			cin>>city1>>city2;
			if(findpar(city1)!=findpar(city2)){
				join(city1,city2);
				uni--;//每两个集团合并,uni-1
			}
		}
		cout<<uni-1<<endl;
	}
	return 0;
}
int findpar(int a)//找a的boss
{
	int r=city[a];//与a联通的城市
	while(city[r]!=r){
		r=city[r];
	}
	int temp;
	while(a!=r){
		temp=city[a];//a的上级
		city[a]=r;
		a=temp;
	}
	return r;
}
int join(int a,int b)
{
	int flag=0;
	int M=findpar(a),N=findpar(b);
	if(M!=N){
		flag=1;
		city[M]=N;
	}
	return flag;
}
