#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,y,z,a,b,c;
	cin>>x>>y>>z;
	a=x+y-z,b=-x+y+z,c=x-y+z;
	if(a%2||b%2||c%2||a<0||b<0||c<0)
		cout<<"Impossible\n";
	else
		cout<<a/2<<' '<<b/2<<' '<<c/2<<endl;
	return 0;
}
