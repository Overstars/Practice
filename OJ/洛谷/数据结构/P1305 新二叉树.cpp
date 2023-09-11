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
map<char,int> TAT;
struct node
{
	char n;
	char lc,rc;
} tree[30];
void show(int x)
{
	if(x==30)
		return;
	cout<<tree[x].n;
	show(TAT[tree[x].lc]);
	show(TAT[tree[x].rc]);
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
	cin>>n;
	TAT['*']=30;
	for(int i=0;i<26;i++)
		TAT['a'+i]=i+1;
	char a,b,c;
	cin>>a>>b>>c;
	int fa=TAT[a];
	tree[fa].n=a;
	tree[fa].lc=b,tree[fa].rc=c;
	for(int i=2;i<=n;i++)
	{
		cin>>a>>b>>c;
		int no=TAT[a];
		tree[no].n=a;
		tree[no].lc=b;
		tree[no].rc=c;
	}
	show(fa);
	return 0;
}
