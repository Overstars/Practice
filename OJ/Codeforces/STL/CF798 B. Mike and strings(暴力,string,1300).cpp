#include<bits/stdc++.h>
using namespace std;
const int maxn=55;
string a[maxn],b[maxn];
int main()
{
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=2;i<=n;i++)
	{
		bool flag=0;
		for(int j=0;j<a[i].length();j++)
		{
			string tem(a[i],j);
			tem+=a[i].substr(0,j);
			if(a[1]==tem)
			{
				flag=1;
				ans+=j;//移动字母个数
				break;
			}
//			cout<<"("<<i<<","<<j<<"):"<<tem<<endl;
		}
		if(!flag)
		{
			cout<<-1<<endl;
			exit(0);
		}
	}
	for(int i=0;i<a[1].length();i++)
	{
		int cnt=0;
		string stdd(a[1],i);
		stdd+=a[1].substr(0,i);
		cnt+=i;
		for(int j=2;j<=n;j++)
		{
			for(int k=0;k<a[j].length();k++)
			{
				string tem(a[j],k);
				tem+=a[j].substr(0,k);
				if(tem==stdd)
				{
					cnt+=k;
					break;
				}
			}
		}
//		cout<<"cnt="<<cnt<<endl;
		ans=min(ans,cnt);
	}
	cout<<ans<<endl;
	return 0;
}
