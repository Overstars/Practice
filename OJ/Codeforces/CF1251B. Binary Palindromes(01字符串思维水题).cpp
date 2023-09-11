#include<bits/stdc++.h>
using namespace std;
char str[55];
int main()
{
//	freopen("CF1251.in","r",stdin);
	int q,n;
	cin>>q;
	while(q--)
	{
		cin>>n;//字符串数
		int qualify=0,qua0=0,qua1=0,fail=0;
		while(n--)//可以跨字符串交换
		{
			cin>>str;
			int len=strlen(str),z=0,o=0;
			for(int i=0;i<len;i++)
				if(str[i]=='0')
					z++;
				else
					o++;
			if(!(z&1)&&!(o&1))//都为偶数
				qualify++;
			else if(!(z&1))//0为偶数
				qua0++;
			else if(!(o&1))//1为偶数个
				qua1++;
			else
				fail++;//都为奇数
		}
		int ans=qualify+qua0+qua1;
		if(fail)
		{
			if(fail&1)
			{
				ans+=fail-1;
				fail=1;
			}
			else
			{
				ans+=fail;
				fail=0;
			}
		}
		if(fail&&(qua0||qua1))
			ans++;
		cout<<ans<<endl;
	}
	return 0;
}
/*
0
2
1
1
3
2
2
*/
