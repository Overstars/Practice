
#include<iostream>
#include<cstdio>
#include<algorithm>
#include <cmath>
using namespace std;
char str[120];
int gcd(int a,int b)
{
	if(a<b)
		swap(a,b);
	int r;
	while((r=a%b)){
		a=b;
		b=r;
	}
	return b;
}
int main()
{
	int t,j,a,v,i,n;
	while(cin>>t){
		a=v=i=n=0;
		scanf("%s",str);
		for(j=0;j<t;j++){
			if(str[j]=='a')
				a++;
			else if(str[j]=='v')
				v++;
			else if(str[j]=='i')
				i++;
			else if(str[j]=='n')
				n++;
		}
		long long ans=a*v*i*n;
		long long ans2=t*t*t*t;
		cout<<ans/gcd(ans,ans2)<<'/';
		if(ans==0)
			cout<<1<<endl;
		else
			cout<<ans2/gcd(ans,ans2)<<endl;
	}
	return 0;
}
