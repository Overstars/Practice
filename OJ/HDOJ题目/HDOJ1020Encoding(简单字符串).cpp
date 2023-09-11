#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>//¿ØÖÆÊä³ö,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
const int inf=0x3f3f3f3f;
char str[10005];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		pair<char,int> arr[10005];
		scanf("%s",str);
		int len=strlen(str),cnt=0;
		char ch;
		for(int i=0,j=1;j<len;)
		{
			ch=str[i];
			while(ch==str[j]&&j<len)
				j++;
			arr[cnt].first=ch;
			arr[cnt++].second=j-i;
			i=j;
		}
		for(int i=0;i<cnt;i++)
			if(arr[i].second>1)
				printf("%d%c",arr[i].second,arr[i].first);
			else
				printf("%c",arr[i].first);
		printf("\n");
	}
	return 0;
}
