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
		uni=n;//���Ÿ���
		int i,city1,city2;
		for(i=1;i<=n;i++)
			city[i]=i;
		for(i=0;i<m;i++){//m����·
			cin>>city1>>city2;
			if(findpar(city1)!=findpar(city2)){
				join(city1,city2);
				uni--;//ÿ�������źϲ�,uni-1
			}
		}
		cout<<uni-1<<endl;
	}
	return 0;
}
int findpar(int a)//��a��boss
{
	int r=city[a];//��a��ͨ�ĳ���
	while(city[r]!=r){
		r=city[r];
	}
	int temp;
	while(a!=r){
		temp=city[a];//a���ϼ�
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
