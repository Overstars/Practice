#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int nex[1000005];
char str[1000005];
void getnext(int n)
{
	nex[0]=0;
	for(int i=1,j=0;i<n;i++){
		while(j>0&&str[i]!=str[j])
			j=nex[j-1];//��str��1��ʼ��¼,jΪ���������һλ
		if(str[i]==str[j])
			j++;
		nex[i]=j;//��Ӧ�Ĺ���������
		if(nex[i]&&(i+1)%(i+1-nex[i])==0)
			printf("%d %d\n",i+1,(i+1)/(i+1-nex[i]));
	}
}
int main()
{
	int t,i,n;
	for(i=1;;i++){
		cin>>n;
		if(!n) break;
		scanf(" %s",str);
		printf("Test case #%d\n",i);
		getnext(n);
		printf("\n");
	}
	return 0;
}
