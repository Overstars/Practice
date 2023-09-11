#include<bits/stdc++.h>
using namespace std;
#define int long long
bool prime(int x)
{
	if(x <= 1)
		return 0;
	if( x == 2 || x == 3 || x == 5 )
		return 1;
	if( x%2 == 0 || x%3 == 0 )	/*判断是否为2,3的倍数*/
		return 0;
	int lim=sqrt((float)x)+1;
	for(int i=6; i<=lim; i += 6 ){//这里可能会有错
		if( x % (i-1) == 0 || x % (i+1) == 0 )
			return 0;
	}
	return 1;
}
signed main()
{
	int n;
	cin>>n;
	if(prime(n))
		cout<<1<<endl;
	else if(n%2==0)//偶数,哥德巴赫猜想
		cout<<2<<endl;
	else//奇数,分类讨论
	{//尝试是否可以拆成两个质数
		if(prime(n-2))//拆出2,因为2是唯一的偶质数,否则剩下的数为偶数不可能是质数
			cout<<2<<endl;
		else
			cout<<3<<endl;
	}
	return 0;
}
