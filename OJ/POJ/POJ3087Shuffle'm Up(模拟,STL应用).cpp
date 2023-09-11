#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
using namespace std;
//char s[2005],s1[1005],s2[1005],s12[2005],save[2005];
string s,s1,s2,s12;
int solve(int n)
{
	int flag=0,step=0,i,j;
//	for(i=0,j=0;i<n;i++){
//		save[j++]=s1[i];
//		save[j++]=s2[i];
//	}
//	save[j]='\0';
	map<string,bool> TAT;
	while(1){
		s12=s;//¿©¥Û»›¡ø= =
		for(i=0,j=0;i<n;i++){
			s12[j++]=s2[i];
			s12[j++]=s1[i];
		}
//		s12[j]='\0';
		step++;
		if(s12.compare(s)==0)
			return step;
		else if(TAT[s12])
			return -1;
//		cout<<s12<<endl;
		TAT[s12]=true;
		for(i=0;i<n;i++)
			s1[i]=s12[i];
		for(j=0;i<2*n;i++,j++)
			s2[j]=s12[i];
	}
	return -1;
}
int main()
{
	int t,n;
	cin>>t;
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		cin>>s1>>s2>>s;
		printf("%d %d\n",i,solve(n));
	}
	return 0;
}
