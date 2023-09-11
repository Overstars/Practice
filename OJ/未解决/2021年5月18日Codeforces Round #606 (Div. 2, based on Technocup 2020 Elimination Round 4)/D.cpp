//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=4e5+10,inf=0x3f3f3f3f,mod=1000000007;
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
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<string> rec(n+1);
		vector<bool> fix(n+1,false);
		vector<int> f[4];//a:00,b:11,c:01,d:10
		vector<int> f01,f10;
		map<string,int>mp;
		string s;
		for(int i=1;i<=n;i++)
		{
			cin>>rec[i];
			if(rec[i][0]==rec[i][rec[i].length()-1])
				continue;
			mp[rec[i]]=i;
			reverse(rec[i].begin(),rec[i].end());
			if(mp.count(rec[i]))//都固定
				fix[i]=fix[mp[rec[i]]]=1;
			reverse(rec[i].begin(),rec[i].end());
		}
		for(int i=1;i<=n;i++)
		{
			s=rec[i];
			int m=s.length(),id=0;
//			mp[s]=i;
			if(s[0]=='0')
			{
				if(s[m-1]=='0')
					id=0;//00
				else
					id=2;//01
			}
			else{
				if(s[m-1]=='0')
					id=3;//10
				else
					id=1;//11
			}
//			reverse(s.begin(),s.end());
//			cerr<<"now = "<<s<<endl;
//			if(mp.count(s)&&id>=2)
			if(fix[i])
			{
				if(id==2)
					f01.push_back(i);
				else
					f10.push_back(i);
			}
			else{
				f[id].push_back(i);
			}
		}//
		int a=f[0].size(),b=f[1].size(),c=f[2].size()+f01.size(),d=f[3].size()+f10.size();
		vector<int>ans;
		if(!c&&!d)
		{
			if(a&&b)
			{
				cout<<-1<<endl;
				continue;
			}
		}
		if(c>d+1)//01>10
		{
			int sub=(c-d)/2;
			if(f[2].size()<sub)
			{
				cout<<-1<<endl;
				continue;
			}
			for(int i=0;i<sub;i++)
				ans.push_back(f[2][i]);
		}
		else if(d>c+1)//10>01
		{
			int sub=(d-c)/2;
			if(f[3].size()<sub)
			{
				cout<<-1<<endl;
				continue;
			}
			for(int i=0;i<sub;i++)
				ans.push_back(f[3][i]);
		}
		cout<<ans.size()<<endl;
		for(auto &i:ans)
			cout<<i<<' ';
		cout<<endl;
	}
	return 0;
}
/*
 * 2021-05-18-13.17.18
 * 单词还必须唯一...
 * 00与11可以任意接在01/10两端而不改变性质
*/

