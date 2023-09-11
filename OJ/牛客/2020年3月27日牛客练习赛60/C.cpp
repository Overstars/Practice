#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e3+5,inf=0x3f3f3f3f,mod=1000000007;
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
//ll dp[maxn][maxn];//以第i个字母作为长度j的结尾的种类数
int main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	set<string>st[maxn];
	map<string,int>mp[maxn];
	map<string,int>::iterator it;//该类型最结尾处
	int n,k;
	cin>>n>>k>>s+1;
	for(int i=1;i<=n;i++)
	{
		string tmp;
		tmp+=s[i];
		st[1].insert(tmp);
		it=mp[1].find(tmp);
		if(it!=mp[1].end())
		{
			continue;
		}
		else{
			mp[1][tmp]=i;
		}
	}
	for(int i=2;i<=k;i++)//子序列长度
	{
		for(string ss:st[i-1])//i-1长度的每种可能
		{
			int pos=mp[i-1][ss];//该种可能的最优下标
			for(int j=pos+1;j<=n;j++)
			{
				string tmp=ss+s[j];
				st[i].insert(tmp);//长度为i
				it=mp[i].find(tmp);
				if(it!=mp[i].end())
				{//存这种可能的最优下标
					it->second=min(it->second,j);
				}
				else{
					mp[i][tmp]=j;
				}
			}
		}
	}
	if(k==0)
		cout<<1<<endl;
	else
		cout<<st[k].size()%mod<<endl;
	return 0;
}


