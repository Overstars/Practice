#include<bits/stdc++.h>
using namespace std;
const int mod=47;
int main()
{
	char a[10],b[10];
	cin>>a>>b;
	int x=1,y=1;
	for(int i=0;i<strlen(a);i++)
		x*=a[i]-'A'+1;
	for(int i=0;i<strlen(b);i++)
		y*=b[i]-'A'+1;
	if(x%mod==y%mod)
		cout<<"GO"<<endl;
	else
		cout<<"STAY"<<endl;
	return 0;
}
