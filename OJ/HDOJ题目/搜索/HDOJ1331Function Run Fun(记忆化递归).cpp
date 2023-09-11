#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int inf=0x3f3f3f3f;
typedef long long ll;
ll w[21][21][21];
//bool vis[21][21][21];//这里是不能用bool的，假如先设一个状态为1，求解这个的子状态会用到标记为1但还未求出的状态，会直接返回初始值0上去
ll f(ll x,ll y,ll z)
{
	if(x<=0||y<=0||z<=0)
		return 1;
	if(x>20||y>20||z>20)
		return w[20][20][20]=f(20,20,20);
	if(w[x][y][z])
		return w[x][y][z];
	if(x<y&&y<z)
		return w[x][y][z]=f(x,y,z-1)+f(x,y-1,z-1)-f(x,y-1,z);
	return w[x][y][z]=f(x-1,y,z)+f(x-1,y-1,z)+f(x-1,y,z-1)-f(x-1,y-1,z-1);
}
int main()
{
	ll a,b,c;
	while(cin>>a>>b>>c&&(a!=-1||b!=-1||c!=-1)){
		printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,f(a,b,c));
	}
	return 0;
}
