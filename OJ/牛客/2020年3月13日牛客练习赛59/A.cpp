#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1005,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
char s[maxn];
int dp1[9],dp2[11];
int main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	cin>>s+1;
	bool a=0,b=0;
	int len=strlen(s+1);
	for(int i=1;i<=len;i++)
	{
		if(s[i]=='X')
		{
			dp1[1]++;
			dp2[1]++;
		}
		else if(s[i]=='i')
		{
			dp1[2]+=dp1[1];
			dp1[6]+=dp1[5];
			dp2[2]+=dp2[1];
			dp2[7]+=dp2[6];
			dp2[10]+=dp2[9];
		}
		else if(s[i]=='a')
		{
			dp1[3]+=dp1[2];
			dp1[7]+=dp1[6];
			dp2[3]+=dp2[2];
		}
		else if(s[i]=='o')
		{
			dp1[4]+=dp1[3];
			dp1[8]+=dp1[7];
			dp2[4]+=dp2[3];
		}
		else if(s[i]=='u')
		{
			dp2[6]+=dp2[5];
			dp2[9]+=dp2[8];
		}
		else if(s[i]=='Q')
			dp1[5]+=dp1[4];
		else if(s[i]=='H')
		{
			dp2[5]+=dp2[4];
			dp2[8]+=dp2[7];
		}
	}
	cout<<((dp1[8]&&dp2[10])?"Happy":"emm")<<endl;
	return 0;
}


