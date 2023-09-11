#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
vector<char>ans;
int cnt[10],rec[10],k;
void dfs(int x,int tot)//x从九开始
{
	if(tot>=k)
		return;
	if(x%3==0&&cnt[x]>0)
	{
		if(tot+cnt[x]>=k)
		{
			rec[x]+=k-tot;
			ans.insert(ans.begin(),k-tot,'0'+x);
			return;
		}
		ans.insert(ans.begin(),cnt[x],'0'+x);
		rec[x]+=cnt[x];
	}
	else
	{
		int now=cnt[x]/3,need=(k-tot)/3;//可以有now个3元组
		//need为可插入三元组
		if(now>=need)//贪心插入三元组
		{
			ans.insert(ans.begin(),need*3,'0'+x);
			tot+=need*3;
			cnt[x]-=need*3;
		}
		else{
			ans.insert(ans.begin(),now*3,'0'+x);
			tot+=now*3;
			cnt[x]-=now*3;
		}
		while(cnt[x]&&k-tot>1)
		{
			if(x==8)
			{
				if(cnt[7])
				{
					tot+=2;
					cnt[8]--;
					cnt[7]--;
					ans.insert(ans.begin(),1,'8');
					ans.insert(ans.begin(),1,'7');
				}
				else if(cnt[4])
				{
					tot+=2;
					cnt[8]--;
					cnt[4]--;
					ans.insert(ans.begin(),1,'8');
					ans.insert(ans.begin(),1,'4');
				}
				else if(cnt[1])
				{
					tot+=2;
					cnt[8]--;
					cnt[1]--;
					ans.insert(ans.begin(),1,'8');
					ans.insert(ans.begin(),1,'1');
				}
				else
					break;
			}
			else if(x==7)
			{
				if(cnt[5])
				{
					tot+=2;
					cnt[7]--;
					cnt[5]--;
					ans.insert(ans.begin(),1,'7');
					ans.insert(ans.begin(),1,'5');
				}
				else if(cnt[2])
				{
					tot+=2;
					cnt[7]--;
					cnt[2]--;
					ans.insert(ans.begin(),1,'7');
					ans.insert(ans.begin(),1,'2');
				}
				else
					break;
			}
			else if(x==5)
			{
				if(cnt[4])
				{
					tot+=2;
					cnt[5]--;
					cnt[4]--;
					ans.insert(ans.begin(),1,'5');
					ans.insert(ans.begin(),1,'4');
				}
			}
			else if(x==2)
			{
				if(cnt[1])
				{
					tot+=2;
					cnt[2]--;
					cnt[1]--;
					ans.insert(ans.begin(),1,'2');
					ans.insert(ans.begin(),1,'1');
				}
			}
		}
	}
	dfs(x-1,tot+rec[x]);
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t;
	cin>>t;
	while(t--)
	{
		memset(cnt,0,sizeof(cnt));
		memset(rec,0,sizeof(rec));
		ans.clear();
		string s;
		cin>>s>>k;
		for(char &c:s)
			cnt[c-'0']++;
		dfs(9,0);
		sort(ans.begin(),ans.end(),greater<char>());
		if(ans.size()==k)
		{
			for(auto &x:ans)
				cout<<x;
			cout<<endl;
		}
		else
			cout<<-1<<endl;
	}
	return 0;
}


