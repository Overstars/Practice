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
	int n,cnt=0,a=97,b=INT_MAX;
	b>>=23;
	cin>>n;
	while(n--)
	{
		int num,i=0;
		cin>>num;
		while(i<4)
		{
//			cout<<i<<"="<<(num&b)<<endl;
			int tem=num&b;
			if(tem==a)
			{
				cnt++;
//				cout<<"HAHAHAHA"<<endl;
			}
			num>>=8;
			i++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
