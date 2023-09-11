#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=505;
ll f[maxn]={0,0,0,6};
int main()
{
	for(int i=4;i<maxn;i++)
		f[i]=f[i-1]+(i-1)*i;
	int x;
	cin>>x;
	cout<<f[x]<<endl;
	return 0;
}
