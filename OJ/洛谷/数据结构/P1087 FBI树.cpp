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
#include<map>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
//#define DEBUG
char str[1<<12];
void tree(int l,int len)
{
	if(len<1)
		return;
	tree(l,len>>1);
	tree(l+(len>>1),len>>1);
	bool f1=0,f0=0;
	for(int i=0;i<len;i++)
		if(str[l+i]=='1')
			f1=1;
		else
			f0=1;
	if(f1&&f0)
		cout<<"F";
	else if(f1)
		cout<<"I";
	else
		cout<<"B";
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
	int n;
//	string str;
	cin>>n>>str+1;
	tree(1,1<<n);
	return 0;
}
