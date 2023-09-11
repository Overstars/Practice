#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int n,x[3],y[3];
int jud(int tx,int ty)
{
	if(tx>x[0]&&ty>y[0])
		return 1;
	if(tx<x[0]&&ty>y[0])
		return 2;
	if(tx<x[0]&&ty<y[0])
		return 3;
	if(tx>x[0]&&ty<y[0])
		return 4;
	return 0;
}
int main()
{

	cin>>n;
	for(int i=0;i<3;i++)
		cin>>x[i]>>y[i];
	if(jud(x[1],y[1])==jud(x[2],y[2]))
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}
