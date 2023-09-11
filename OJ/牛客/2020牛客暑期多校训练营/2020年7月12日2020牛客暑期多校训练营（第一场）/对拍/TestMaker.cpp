#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const string LLMax="9223372036854775807";
const string IntMax="2147483647";
const int intDigit = 10;
const int llDigit = 19;
string randIntNum(int digit, bool isHasZero, bool isGetNegative)
{
	int n = rand() % digit + 1; 	//需要生成的位数
	string randNumString = "";
	if(n == intDigit)
	{
		randNumString += (rand() % 2 + 1 + '0');
		for(int i = 1; i < n; i++)
		{
			int tmp = rand() % 10;
			while(tmp > (IntMax[i] - '0'))
				tmp = rand() % 10;
			randNumString += (tmp + '0');
		}
	}
	else if(n == 1)
	{
		if(isHasZero)
			randNumString += (rand() % 10 + '0');
		else
			randNumString += (rand() % 9 + 1 + '0');
	}
	else
	{
		randNumString += (rand() % 9 + 1 + '0');
		for(int i = 2; i <= n; i++)
		{
			int tmp = rand() % 10;
			randNumString += (tmp + '0');
		}
	}
	if(isGetNegative)
	{
		if(rand() % 2 && randNumString[0] != '0')
		{
			randNumString = "-" + randNumString;
		}
	}
	return randNumString;
}
string randLLNum(int digit, bool isHasZero, bool isGetNegative)
{
	int n = rand() % digit + 1; 	//需要生成的位数
	string randNumString = "";
	if(n == llDigit)
	{
		randNumString += (rand() % 2 + 1 + '0');
		for(int i = 1; i < n; i++)
		{
			int tmp = rand() % 10;
			while(tmp > (LLMax[i] - '0'))
				tmp = rand() % 10;
			randNumString += (tmp + '0');
		}
	}
	else if(n == 1)
	{
		if(isHasZero)
			randNumString += (rand() % 10 + '0');
		else
			randNumString += (rand() % 9 + 1 + '0');
	}
	else
	{
		randNumString += (rand() % 9 + 1 + '0');
		for(int i = 2; i <= n; i++)
		{
			int tmp = rand() % 10;
			randNumString += (tmp + '0');
		}
	}
	if(isGetNegative)
	{
		if(rand() % 2 && randNumString[0] != '0')
		{
		randNumString = "-" + randNumString;
		}
	}
	return randNumString;
}
int getxp(int l,int r)//得到大于l小于r的数
{
	return (int)(round(1.0*rand()/RAND_MAX*r+l));
}
const double delta=0.73;
ll lim5=100000,lim6=1000000;
int main()
{
//	ios::sync_with_stdio(false);
//	freopen("test5.in", "w", stdout);
	srand(time(0));
	int n=6,m=getxp(2,5),k=getxp(1,n);
//	cout<<n<<' '<<m<<' '<<k<<endl;
	while(m--)
	{
		int n=getxp(3,6);
		cout<<n<<endl;
		for(int i=1;i<=n;i++)
			cout<<getxp(0,10)<<' ';
		cout<<endl;
//		ll l,r;
//		r=getxp(1,t);
//		l=getxp(1,r);
//		cout<<l<<' '<<r<<endl;
	}
//	cout<<"cnt1="<<cnt1<<","<<"cnt2="<<cnt2<<endl;
	return 0;
}

