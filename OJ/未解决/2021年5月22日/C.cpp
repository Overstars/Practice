//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=2e6+10,inf=0x3f3f3f3f,mod=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;
const double eps=1e-9;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
char s[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t=1;
	while(t--)
	{
		cin>>s+1;
		int n=strlen(s+1),l=1,r=n,p=0;
		for(int i=1;i<=n;i++)
			if(s[i]=='.')
			{
				p=i;
				break;
			}
		if(!p)
		{
			s[n+1]='.';
			p=n+1;
			n++;
		}
		string a,b;
		bool ok=0;
		for(int i=1;i<p;i++)
		{
			if(!ok&&s[i]=='0')
				continue;
			ok=1;
			a+=s[i];
		}
	//	cerr<<a<<endl;
		for(int i=p+1;i<=n;i++)
		{
			b+=s[i];
		}
		while(b.length()>=1&&b[b.length()-1]=='0')
			b.pop_back();
		if(a.empty()&&b.empty())
		{
			return cout<<0<<endl,0;
		}
		if(a.empty())
		{//小数点全面全是0
			int m=b.length();
			int len=0;
			for(int i=0;i<m;i++)
				if(b[i]!='0')
				{
					len=i;
					break;
				}
			cout<<b[len];//第一个不为0的数
			if(m>len+1)
			{//还有剩余的数
				cout<<".";
			}
			for(int i=len+1;i<m;i++)
				cout<<b[i];
			cout<<"E-"<<len+1<<endl;
		}
		else{
			if(a.length()==1)
			{
				cout<<a;
				if(!b.empty())
					cout<<'.'<<b;
				cout<<endl;
			}
			else// if(a.length()>1)
			{
				int cnt=0;
				int nn=a.length();
				for(int i=nn-1;i>=0;i--)
				{
					if(a[i]!='0')
						break;
					cnt++;
				}
				if(cnt==nn-1&&b.empty())
					cout<<a[0]<<"E"<<nn-1<<endl;
				else{
					cout<<a[0]<<'.';
					if(!b.empty())
					{
						for(int i=1;i<nn;i++)
							cout<<a[i];
						cout<<b<<"E"<<nn-1<<endl;
					}
					else{
						for(int i=1;i<nn-cnt;i++)
							cout<<a[i];
						cout<<"E"<<nn-1<<endl;
					}
				}
			}
		}
	}
//	for(int i=l;i<=r;i++)
//		t+=s[i];
//	cerr<<t<<endl;
	return 0;
}
/*
1
11
.0001
.123
123.
123.123
1000
00.00123
.000012300
12300.00
12300.00123
12300.12300
000123.00123
0012300.0012300
*/
/*
 *
 * 2021-05-22-15.01.37
 * C:\Users\dell\Desktop\C++\OJ\未解决\2021年5月22日\C.cpp
 *
*/

