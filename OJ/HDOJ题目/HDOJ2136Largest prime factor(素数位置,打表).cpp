#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000001
using namespace std;
int ans[maxn];
int main()
{
	memset(ans,-1,sizeof(ans));
	ans[1]=0;
	int i,j,cnt=0;
	for(i=2;i<maxn;i++)//˵��iΪ����
		if(ans[i]==-1){
			cnt++;//��������
			for(j=i;j<maxn;j+=i)//i�����б���
				ans[j]=cnt;
		}
	while(scanf("%d",&i)==1)
		printf("%d\n",ans[i]);
	return 0;
}
