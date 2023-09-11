//设第n项错排数为F(n),则n-1项为F(n-1)
//1.将第n个元素放在其他位置，一共有n-1种，假设放在第k个位置
//2.放置第k个元素，有两种可能：
//①k放在第n个位置，n放在k的位置，剩下n-2个元素错排，一共F(n-1)种可能
//②k不放在第n个位置，n-1个元素错排，一共F(n-2)种可能
//递推公式F(n)=(n-1)*[F(n-2)+F(n-1)]
#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	long long F[30]={0,0,1},all=2;//all是所有组合的可能个数
	double rate[30]={0,0,0.5};
	int i,t;
	for(i=3;i<22;i++){
		F[i]=(i-1)*(F[i-2]+F[i-1]);
		all*=i;
		rate[i]=(double)F[i]/all;
	}
	int c;
	cin>>c;
	while(c--){
		cin>>t;
		printf("%.2lf%%\n",rate[t]*100);
	}

	return 0;
}
