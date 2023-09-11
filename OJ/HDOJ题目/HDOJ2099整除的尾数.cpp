#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a,b,i,cnt,ans[100];
	while(cin>>a>>b&&(a||b)){
		cnt=0;
		for(i=1;i*b<a*100+100;i++){
			if((i*b/100)==a){
				ans[cnt++]=i*b%100;
			}
		}
		for(i=0;i<cnt;i++){
			printf("%02d",ans[i]);
			if(i!=cnt-1)
				cout<<' ';
			else
				cout<<'\n';
		}
	}
	return 0;
}
