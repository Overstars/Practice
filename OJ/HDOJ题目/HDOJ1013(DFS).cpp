#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int isprime(int x);
void dfs(int x);
int flag[20],ans[21]={0,1};//����1~n
int n;
int main()
{
	int cnt=0;
	while(cin>>n){
		memset(flag,0,sizeof(flag));
		printf("Case %d:\n",++cnt);
		dfs(2);
		putchar('\n');
	}
	return 0;
}
void dfs(int x)//Ϊ��ʱ�뿪ʼ��x��λ�����
{
	if(x==n+1&&isprime(ans[n]+ans[1])){//n����ȫ������,����Ҷ�ӽڵ�,��������ظ��ڵ�
		printf("%d",ans[1]);
		int i;
		for(i=2;i<=n;i++)
			printf(" %d",ans[i]);
		putchar('\n');
	}
	else{
		int i;
		for(i=2;i<=n;i++){
			if(!flag[i]&&isprime(ans[x-1]+i)){//��������ʣ�µ�����������,�����õ����޷�����һ���������������÷�֧����
				ans[x]=i;
				flag[i]=1;//��Ǹýڵ��õ�����ֵ����ֹ�ӽڵ�ʹ�ø���
				dfs(x+1);//�������ڵ��ӽڵ�
				flag[i]=0;//�÷�֧������,���ظ��ڵ�ǰ��������
			}
		}
	}
	return;
}
int isprime(int x)
{
	if(x==0||x==1)
		return 0;
	int i;
	for(i=2;i<=sqrt(x);i++)
		if(x%i==0)
			return 0;
	return 1;
}
