#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=205;
vector<int> G[maxn];
int linker[maxn];
bool stay[maxn],used[maxn],stu[maxn];
bool dfs(int x)//
{
	for(auto &v:G[x])
		if(!used[v])//在右边找
		{
//			cout<<x<<"还没有床铺"<<endl;
			used[v]=1;
			if(!linker[v]||dfs(linker[v]))
			{
//				cout<<x<<"找到了床铺"<<endl;
				linker[v]=x;//记录右边v号匹配
				return 1;
			}
		}
	return 0;//未找到增广路
}
int hungry(int n)
{
	int ans=0;
	memset(linker,0,sizeof(linker));
	for(int i=1;i<=n;i++)//遍历左面
	{
		memset(used,0,sizeof(used));
		if(dfs(i))//能找到增广路
			ans++;
	}
	return ans;
}
signed main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		memset(stay,0,sizeof(stay));
//		memset(stu,0,sizeof(stu));
		cin>>n;
		for(int i=1;i<=n;i++)
			G[i].clear();
		int ope=0;
		for(int i=1;i<=n;i++)
		{
			cin>>ope;
			if(ope)
				stu[i]=1;//是在校学生
			else
				stu[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>ope;
			if(stu[i])
			{
				if(ope==0)//留校
					stay[i]=1;
				else if(ope==1)//回家
					stay[i]=0;
			}
			else//无关人员
				stay[i]=1;//住校
		}
		for(int i=1;i<=n;i++)//
		{
			if(stay[i]&&stu[i])//住校,且为学生
				G[i].push_back(i);//自己可以睡自己的
			for(int j=1;j<=n;j++)
			{
				int know=0;
				cin>>know;
				if(stay[i]&&know&&stu[j])//j有床位
				{//注意特判i住校
					G[i].push_back(j);
				}
			}
		}
		int needs=0;
		for(int i=1;i<=n;i++)
		{
			if(!stu[i]||(stu[i]&&stay[i]))
				needs++;
		}
		if(hungry(n)==needs)
			cout<<"^_^"<<endl;
		else
			cout<<"T_T"<<endl;
	}
	return 0;
}
/*
 *用邻接矩阵做更简单,我开邻接表是作死...
 *该题很容易看出来要让人和床建二分图
 *搭嘎
 */
