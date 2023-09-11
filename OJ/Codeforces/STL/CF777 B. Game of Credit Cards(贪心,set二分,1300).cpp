#include<bits/stdc++.h>
using namespace std;
const int maxn=1005,inf=0x3f3f3f3f;
int s[maxn],m[maxn];
int main()
{//m最少惩罚次数,s最多惩罚次数
	int n,ans1=0,ans2=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char ch;
		cin>>ch;
		s[i]=ch-'0';
	}
	for(int i=1;i<=n;i++)
	{
		char ch;
		cin>>ch;
		m[i]=ch-'0';
	}
	multiset<int> st;
	st.insert(inf);
	for(int i=1;i<=n;i++)
		st.insert(m[i]);
	std::multiset<int>::iterator p;
	for(int i=1;i<=n;i++)
	{
		p=st.lower_bound(s[i]);
		if(*p!=inf)//找到>=s[i]的
			st.erase(p);//不要移除所有的
		else//m必须被惩罚
			ans1++;
	}
	cout<<ans1<<endl;
	st.clear();
	st.insert(inf);
	for(int i=1;i<=n;i++)
		st.insert(m[i]);
	for(int i=1;i<=n;i++)//s最多惩罚次数
	{
		p=st.upper_bound(s[i]);//找到比s[i]大的
		if(*p!=inf)
			st.erase(p),ans2++;
	}
	cout<<ans2<<endl;
	return 0;
}
