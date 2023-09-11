#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f;
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
//#define DEBUG
char st[5]={'a','e','i','o','u'};
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll k,lim,s=LLONG_MAX,r=0;
	cin>>k;
	lim=sqrt(k)+1;
	for(int i=5;i<=lim;i++)
		if(k%i==0)
		{
			s=i;
			r=k/s;
			break;
		}
	if(s>r)
	{
		cout<<-1<<endl;
	}
	else{
		for(ll i=0;i<s;i++)
		{
			for(ll j=0;j<r;j++)
			{
				cout<<st[(i+j)%5];
			}
		}
	}
	return 0;
}


