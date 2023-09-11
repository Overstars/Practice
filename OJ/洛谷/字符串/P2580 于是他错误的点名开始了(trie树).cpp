#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int trie[maxn][26],sum[maxn],tot=1;
bool isw[maxn];
void Insert(const string &s,int rt)
{
	for(int i=0;i<s.length();i++)
	{
		int id=s[i]-'a';
		if(!trie[rt][id])//该字母之前未出现
			trie[rt][id]=++tot;
		rt=trie[rt][id];//移动到下个节点
	}
	isw[rt]=1;//标记为一个完整单词
}
int Find(const string &s,int rt)
{
	for(int i=0;i<s.length();i++)
	{
		int id=s[i]-'a';
		if(!trie[rt][id])
			return 0;
		rt=trie[rt][id];
	}
	sum[rt]++;
	if(isw[rt]&&sum[rt]==1)
		return 1;
	else if(isw[rt])
		return 2;
	else
		return 0;
}
int main()
{
	int n,m;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		Insert(s,1);
	}
	cin>>m;
	while(m--)
	{
		cin>>s;
		int f=Find(s,1);
		if(f==1)
			cout<<"OK\n";
		else if(f==2)
			cout<<"REPEAT\n";
		else
			cout<<"WRONG\n";
	}
	return 0;
}
