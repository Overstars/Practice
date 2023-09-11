#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<climits>
#include<cmath>
#include<iomanip>//¿ØÖÆÊä³ö,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<map>
//#define lowbit(x) ((x) & -(x))
#define PI 3.14159265358979323846
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=200005;
//#define DEBUG
char a[17]="0123456789ABCDEF";
void trans(int n,int r)
{
    if(n==0)
        return;
    if(0<n&&n<=r){
        putchar(a[n]);
        return;
    }
    else{
        trans(n/r,r);
        putchar(a[n%r]);
    }
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	int n,d;
	while(cin>>n>>d)
	{
		double s=0,theta;
		for(int i=0;i<n;i++)
		{
			cin>>theta;
			s+=(double)d*d*sin(theta*PI/180)/2;
		}
		cout<<setiosflags(ios::fixed)<<setprecision(3)<<s<<endl;
	}
	return 0;
}
