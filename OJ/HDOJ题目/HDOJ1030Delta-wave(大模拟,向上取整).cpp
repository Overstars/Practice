#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>//¿ØÖÆÊä³ö,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
const int inf=0x3f3f3f3f;
int main()
{
	long n,m;
	while(cin>>n>>m)
	{
		long nlevel=(long)ceil(sqrt(n));
		long mlevel=(long)ceil(sqrt(m));
		long nleft=(n-(nlevel-1)*(nlevel-1)+1)/2;
		long mleft=(m-(mlevel-1)*(mlevel-1)+1)/2;
		long nright=((nlevel*nlevel+2)-n)/2;
		long mright=((mlevel*mlevel+2)-m)/2;
//		printf("level:%d,%d left:%d,%d right:%d,%d\n",nlevel,mlevel,nleft,mleft,nright,mright);
		cout<<abs(nleft-mleft)+abs(nlevel-mlevel)+abs(nright-mright)<<endl;
	}
	return 0;
}
