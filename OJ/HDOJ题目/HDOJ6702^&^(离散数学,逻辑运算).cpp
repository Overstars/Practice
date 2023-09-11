#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
const int inf=0x3f3f3f3f;
int main()
{
	int t;
	cin>>t;
	while(t--){
		long long a,b,c;
		cin>>a>>b;
		c=a&b;//异或相同为0
		if(c)
			cout<<c<<endl;
		else
			cout<<1<<endl;
	}
	return 0;
}
