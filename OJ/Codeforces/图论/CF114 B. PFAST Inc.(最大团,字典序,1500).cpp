#include<bits/stdc++.h>
using namespace std;
const int maxn=20;
int n,m;
bool G[maxn][maxn];
int cnt[maxn];//cnt[i]为>=i的最大团点数
int group[maxn];//最大团的点
int vis[maxn];//记录点的位置
int res;//最大团的数目
bool dfs(int pos,int num)
{//num为当前独立集中的点数
    for(int i=pos+1;i<=n;i++)
	{
        if(cnt[i]+num<=res)//剪枝，若取i但cnt[i]+已经取了的点数仍<ans
            return false;
        if(G[pos][i])
        {//与当前团中元素比较，取Non-maxn(i)
            int j;
            for(j=0;j<num;j++)
                if(!G[i][vis[j]])
                    break;
            if(j==num)
            {//若为空，则皆与i相邻，则此时将i加入到最大团中
                vis[num]=i;
                if(dfs(i,num+1))
                    return true;
            }
        }
    }
    if(num>res){//每添加一个点最多使最大团数+1,后面的搜索就没有意义了
        for(int i=0;i<num;i++)//最大团的元素
            group[i]=vis[i];
        res=num;//最大团中点的数目
        return true;
    }
    return false;
}
void maxClique()
{
    res=-1;
    for(int i=n;i>0;i--)
	{//枚举所有点
        vis[0]=i;
        dfs(i,1);
        cnt[i]=res;
    }
}
map<string,int> mp;
map<int,string>pm;
bool cmp(int x,int y)
{
	if(pm[x]<pm[y])
		return 1;
	return 0;
}
int main()
{
	string s,s2;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		mp[s]=i;
		pm[i]=s;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			G[i][j]=1;
	for(int i=1;i<=m;i++)
	{
		cin>>s>>s2;
		G[mp[s]][mp[s2]]=G[mp[s2]][mp[s]]=0;
	}
//	for(int i=1;i<=n;i++)//建立反图,该题不需要
//		for(int j=1;j<=n;j++)
//		{
//			if(i==j)
//				G[i][j]=0;
//			else
//				G[i][j]^=1;
//		}
	maxClique();
	cout<<res<<endl;//大小
	sort(group,group+res,cmp);//字典序
	for(int i=0;i<res;i++)
		cout<<pm[group[i]]<<endl;
	return 0;
}
