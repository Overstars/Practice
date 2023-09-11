//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
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
int x,y;
bool near(int nx,int ny)
{
	return abs(x-nx)+abs(y-ny)>=2;
}
bool equ(int nx,int ny)
{
	return (nx==x)&&(ny==y);
}
bool check(string &s)
{
	int nx=0,ny=0;
	bool ok=1;
	if(equ(nx,ny))
		ok=0;
	for(char &ch:s)
	{
		if(ch=='U')
			ny++;
		else if(ch=='D')
			ny--;
		else if(ch=='L')
			nx--;
		else
			nx++;
		if(equ(nx,ny))
			ok=0;
	}
	return ok;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>x>>y;
		cin>>s;
		int tx=0,ty=0;
		map<char,int>mp;
		for(char &ch:s)
		{
			mp[ch]++;
			if(ch=='U')
				ty++;
			else if(ch=='D')
				ty--;
			else if(ch=='L')
				tx--;
			else
				tx++;
//			if(tx==x&&ty==y)
//				vis=1;
		}
		#define endl '\n'
//		if((x==0&&y==0)||(tx==x&&ty==y))
//			cout<<"Impossible"<<endl;
//		else if(mp.size()==2)
//		{//一定有解,不在路线上
//			cout<<s<<endl;
//		}
//		else{//路线有多种
			string ans;
			bool ok=1;
			int nx=0,ny=0,stp=0,n=s.length();
			if(equ(nx,ny))
				ok=0;
			while(stp<n)
			{
				stp++;
				if(mp['U']>0&&!equ(nx,ny+1))
				{
					ny++;
					mp['U']--;
					ans+='U';
					continue;
				}
				if(mp['D']>0&&!equ(nx,ny-1))
				{
					ny--;
					mp['D']--;
					ans+='D';
					continue;
				}
				if(mp['L']>0&&!equ(nx-1,ny))
				{
					nx--;
					mp['L']--;
					ans+='L';
					continue;
				}
				if(mp['R']>0&&!equ(nx+1,ny))
				{
					nx++;
					mp['R']--;
					ans+='R';
					continue;
				}
				ok=0;//n轮每轮都会取走一个字符
				break;
			}
//			fprintf(stderr,"ok = %d\n",check(ans));
//			cerr<<"ans = "<<ans<<endl;
			if(!ok)
				cout<<"Impossible";
			else
				cout<<ans;
//		}
		if(t)
			cout<<endl;
	}
	return 0;
}
/*
 * 2021-06-04-15.39.57
 * C:\Users\dell\Desktop\2021年6月4日2020-2021 ACM-ICPC, Asia Nanjing Regional Contest (XXI Open Cup, Grand Prix of Nanjing)\E.cpp
 *
*/

