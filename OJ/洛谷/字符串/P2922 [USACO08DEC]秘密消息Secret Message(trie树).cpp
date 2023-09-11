#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int trie[maxn][5],tot=1,sum[maxn];
int isw[maxn];
void Insert(const string &s,int rt)
{
	for(auto &ch:s)
	{
		int id=ch-'0';
		if(!trie[rt][id])
			trie[rt][id]=++tot;
		rt=trie[rt][id];
		sum[rt]++;
	}
	isw[rt]++;//可能有重复串
}
int Find(const string &s,int rt)
{
	int cnt=0;
	for(int i=0;i<s.length();i++)
	{
		int id=s[i]-'0';
		if(!trie[rt][id])
			return cnt;
		rt=trie[rt][id];
		if(isw[rt]&&i<s.length()-1)
			cnt+=isw[rt];//统计s的前缀个数
	}
	cnt+=sum[rt];//统计s作为前缀的个数
//	cout<<s<<":"<<cnt<<endl;
	return cnt;
}
int main()
{
//	freopen("P2922_2.in","r",stdin);
	int m,n,l;
	cin>>m>>n;
	char ch;
	for(int i=0;i<m;i++)
	{
		string str;
		cin>>l;
		for(int j=0;j<l;j++)
		{
			cin>>ch;
			str+=ch;
		}
		Insert(str,1);
	}
	for(int i=0;i<n;i++)
	{
		string str;
		cin>>l;
		for(int j=0;j<l;j++)
		{
			cin>>ch;
			str+=ch;
		}
		cout<<Find(str,1)<<endl;
	}
	return 0;
}
