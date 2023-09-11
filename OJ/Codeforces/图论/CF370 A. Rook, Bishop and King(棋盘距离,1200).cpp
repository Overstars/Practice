#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	if(x1==x2&&y1==y2)
		cout<<0<<' ';
	else if(x1==x2||y1==y2)
		cout<<1<<' ';
	else
		cout<<2<<' ';
	if(x1==x2&&y1==y2||(((x1+y1)&1)!=((x2+y2)&1)))
		cout<<0<<' ';
	else if(abs(x1-x2)==abs(y1-y2))
		cout<<1<<' ';
	else
		cout<<2<<' ';
	cout<<max(abs(x1-x2),abs(y1-y2))<<endl;
	return 0;
}
