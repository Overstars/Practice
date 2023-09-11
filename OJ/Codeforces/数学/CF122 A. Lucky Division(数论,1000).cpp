#include<bits/stdc++.h>
using namespace std;
int a[15]={4,44,444,7,77,777,47,447,477,74,774,744,474,747};
bool jud(int x)
{

	for(int i=0;i<14;i++)
	{
		if(x==a[i]||x%a[i]==0)
			return 1;
	}
	return 0;
}
int main()
{
	int n;
	cin>>n;
	cout<<(jud(n)?"YES\n":"NO\n");
	return 0;
}
