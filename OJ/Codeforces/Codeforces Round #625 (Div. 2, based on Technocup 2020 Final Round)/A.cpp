/*
 * @Author: Overstars
 * @Date: 2020-03-02 21:50:10
 * @LastEditTime: 2022-02-13 14:28:51
 * @LastEditors: Overstars
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int r[maxn],b[maxn],p[maxn];
int main()
{
	cout << __cplusplus << endl;
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,cr=0,cb=0,equ=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>r[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	bool flag=0;
	for(int i=1;i<=n;i++)
	{
		if(r[i]==b[i])//全部�?1
			equ++;
		else if(r[i])
			cr++;
		else
			cb++;
	}
	if(cr==0)
		cout<<-1<<endl;
	else{//答�?�为(cb+1)/(cr)向上取整
		int ans=(cb+1)/cr;
		if((cb+1)%cr)
			ans++;
		cout<<ans<<endl;
	}
	return 0;
}


