#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<string>
#include<stack>
#include<map>
#include<set>
using namespace std;
const int inf=0x3f3f3f3f;
int main()
{
	int n;
	while(cin>>n&&n)
	{
		set<string> all,lose;
		string a,b;
		for(int i=0;i<n;i++)
		{
			cin>>a>>b;//前者战胜后者
			all.insert(a);
			all.insert(b);
			lose.insert(b);
		}
		if(all.size()-lose.size()==1)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
