#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
ll pow(ll a,ll b)
{
	ll ans=1;
	while(b>0){
		if(b&1)
			ans*=a;
		a*=a;
		b>>=1;
	}
	return ans;
}
long long pre[10]={0,9};
int main()
{
	for(int i=2;i<10;i++)
	{//数目*价值
		pre[i]=(pow(10,i)-pow(10,i-1))*i+pre[i-1];
//		cout<<"pre["<<i<<"]="<<pre[i]<<endl;
	}
	int n,x,k=0;
	cin>>n;
	x=n;
	while(x>0)
	{
		x/=10;
		k++;
	}//有k位
	cout<<pre[k-1]+(n-pow(10,(ll)k-1)+1)*k<<endl;
	return 0;
}
