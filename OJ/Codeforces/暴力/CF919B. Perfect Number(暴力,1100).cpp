#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
int rec[maxn]={0,19,28,37,46,55,64,73,82,91,109};
bool jud(int x)
{
	int sum=0;
	while(x)
	{
		sum+=x%10;
		x/=10;
		if(sum>10)
			return 0;
	}
	if(sum==10)
		return 1;
	else
		return 0;
}
int main()
{
	int k,cnt=0;
	cin>>k;
	for(int i=19;cnt<=k;i++)
		if(jud(i))
			rec[++cnt]=i;
	cout<<rec[k]<<endl;
	return 0;
}
