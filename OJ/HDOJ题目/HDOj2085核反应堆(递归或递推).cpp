#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
long long h[35]={1},l[35]={0},flagh[35]={1},flagl[35]={1};
long long funh(int x);
long long funl(int x);
int main()
{
	int n;
	while(cin>>n&&n!=-1){
		cout<<funh(n)<<','<<' '<<funl(n)<<endl;
	}
	return 0;
}
long long funh(int x)
{
	if(flagh[x]){
		return h[x];
	}
	else{
		flagh[x]=1;
		return h[x]=3*funh(x-1)+2*funl(x-1);//之前的高能粒子被吸收,放出3个高能和1个低能
	}
}
long long funl(int x)
{
	if(flagl[x]){
		return l[x];
	}
	else{
		flagl[x]=1;
		return l[x]=funh(x-1)+funl(x-1);//上一级低能被吸收，放出2个高能和1个低能
	}
}
