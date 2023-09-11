#include<bits/stdc++.h>
using namespace std;
bool jud(int a,int b,int c,int n)
{
	 if(a>b)
		swap(a,b);
	 if(b>c)
		swap(b,c);
	 if(a>b)
		swap(a,b);
	 if(b==a+1&&c==b+1)
		return 1;
	 else if(a==0&&c==n-1&&b==c-1)
		return 1;
	 else
		return 0;
}
int main()
{
	int n,a,b,c;
	cin>>n;
	cin>>a>>b>>c;
	if(n%2&&!jud(a,b,c,n))
	{//当n为偶数且黑三角不在边上时,后手才会赢
		cout<<"PZ Win"<<endl;
	}
	else
		cout<<"JMcat Win"<<endl;
	return 0;
}
