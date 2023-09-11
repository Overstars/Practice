#include<bits/stdc++.h>
using namespace std;
string s;
bool jud(const char &ch)
{
	if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
		return 0;
	return 1;
}
int main()
{
	cin>>s;
	int cnt=0,pc=0;
	char pre='a';
	bool flag=0;//
	for(char &ch:s)
	{
		if(!jud(ch))//元音
			cnt=0;
		else
			cnt++;
		if(pre==ch)//连着几个相同辅音
			pc++;
		else if(jud(ch))//新的辅音
			pc=1;
		pre=ch;
//		printf("%d,%d\n",cnt,pc);
		if(cnt>=3)//第三个辅音
		{
			if(pc<cnt)//不是相同的
			{
				cout<<' ';
				cnt=1;
			}
		}
		cout<<ch;
	}
	return 0;
}
/*
 dfacccbabc
 */
