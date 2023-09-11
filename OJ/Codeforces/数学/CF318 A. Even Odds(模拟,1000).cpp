#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,k;
	cin>>n>>k;
	if(k<=(n/2+n%2))//奇数
		cout<<(k-1)*2+1;
	else
		cout<<(k-(n/2+n%2))*2<<endl;
	return 0;
}
