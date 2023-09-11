#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
int main()
{
	int i,j;
	char s[15];
	string str;
	map<string,int> QAQ;
	while(gets(s)){
		if(s[0]=='\0')
			break;
		for(i=strlen(s);i>0;i--){
			s[i]='\0';
			str=s;
			QAQ[str]++;
		}
	}
	while(scanf("%s",s)==1){
		cout<<QAQ[s]<<endl;
	}
	return 0;
}
