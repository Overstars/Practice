#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<climits>
#include<cmath>
#include<iomanip>//控制输出,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<map>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
//#define DEBUG
void dfs(string a,string b)//对a
{
	if(a.size()<=0)
		return;
	char ch=b[b.size()-1];
	cout<<ch;
	int div=a.find(ch);
	dfs(a.substr(0,div),b.substr(0,div));//第二个参数为长度
	dfs(a.substr(div+1),b.substr(div,a.size()-div-1));
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
	string a,b;
	cin>>a>>b;
	dfs(a,b);
	return 0;
}
