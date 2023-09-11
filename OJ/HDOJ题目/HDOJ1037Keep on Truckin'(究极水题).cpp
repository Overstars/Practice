#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>//¿ØÖÆÊä³ö,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
const int inf=0x3f3f3f3f;
int main()
{
	int a,b,c;
	while(cin>>a>>b>>c)
	{
		if(a<=168)
			cout<<"CRASH "<<a<<endl;
		else if(b<=168)
			cout<<"CRASH "<<b<<endl;
		else if(c<=168)
			cout<<"CRASH "<<c<<endl;
		else
			cout<<"NO CRASH"<<endl;
	}
	return 0;
}
