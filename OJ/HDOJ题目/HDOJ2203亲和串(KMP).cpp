#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int flag,nex[100005];
char s1[100005],s2[100005],s3[100005];
void getnext(int n2)
{
	nex[0]=0;
	int i,j;
	for(i=1,j=0;i<n2;i++){
//		j=nex[i-1];
		while(j>0&&s2[j]!=s2[i])
			j=nex[j-1];
		if(s2[j]==s2[i])
			j++;
		nex[i]=j;
	}
}
void kmp(int n1,int n2)
{
	int i,cmp=0,cnt;
	for(i=0;i<n1;i++){//
		while(cmp>0&&s1[i]!=s2[cmp])//
			cmp=nex[cmp-1];
		if(s1[i]==s2[cmp])
			cmp++;
		if(cmp==n2){
			flag=1;
			break;
		}
	}
}
int main()
{
	while(scanf("%s %s",s3,s2)==2){
		flag=0;
		strcpy(s1,s3);
		strcat(s1,s3);
//		cout<<"This:"<<s1<<endl;
		getnext(strlen(s2));
		kmp(strlen(s1),strlen(s2));
		if(flag)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}
