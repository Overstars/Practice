#include<bits/stdc++.h>
using namespace std;
bool prime( int x )
{
	if(x <= 1)
		return 0;
	if( x == 2 || x == 3 || x == 5 )
		return 1;
	if( x%2 == 0 || x%3 == 0 )	/*判断是否为2,3的倍数*/
		return 0;
	for(int i=6; i<=sqrt((float)x); i += 6 ){//这里可能会有错
		if( x % (i-1) == 0 || x % (i+1) == 0 )
			return 0;
	}
	return 1;
}
int main()
{
	int n;
	cin>>n;
	if(n%2)
		cout<<3<<endl;
	else{
		for(int i=1;i<=100;i++)
			if(!prime(n*i+1))
			{
				cout<<i<<endl;
				break;
			}
	}
	return 0;
}
