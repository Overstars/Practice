#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
char s[9],st[6];//3,4\1,6\2,8
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	srand(time(0));//2,1,9,7,7,4,1,3,9
//	for(int i=0;i<6;i++)
//		st[i]='A'+(rand())%26;
	int ope=0;
	while(cin>>ope)
	{
		st[1]='A'+ope;
		st[0]=st[1]+1;
		st[2]=st[1]+8;
		st[3]=st[1]+6;
		st[4]=st[1]+3;
		st[5]=st[1]+2;
		printf("%c%c%c%c%c%c%c%c%c\n",st[0],st[1],st[2],st[3],st[3],st[4],st[1],st[5],st[2]);
	}
//	printf("WQOUURQEO");
	return 0;
}


