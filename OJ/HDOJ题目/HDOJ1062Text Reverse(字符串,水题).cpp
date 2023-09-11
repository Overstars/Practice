#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	char str[1005];
	int n;
	cin>>n;
	getchar();
	while(n--){
		char *ps=str,*pe=str;
		gets(str);
		while(*ps!='\0'){
			while(*pe!=' '&&*pe!='\0')
				pe++;
			char *p=pe-1;
			while(ps<p){
				char temp=*p;
				*p=*ps;
				*ps=temp;
				p--;
				ps++;
			}
			while(*pe==' ')
				pe++;
			ps=pe;
		}
		puts(str);
	}
	return 0;
}
