#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
const int inf=0x3f3f3f3f,mn=11,mlen=105;
char s[mlen],str[mn][mlen],ans[mlen],temp[mlen];
int nex[mlen];
void getnex(char *st,int n)//处理字符串,长度
{
	nex[0]=0;
	for(int i=1,j=0;i<n;i++)
	{
		while(j>0&&st[j]!=st[i])
			j=nex[j-1];
		if(st[i]==st[j])
			j++;
		nex[i]=j;
	}
}
bool kmp(char *tem,int m,char *st,int n)//子串,子串长度,匹配模板串,模板串长度
{
	int cmp=0;
	for(int i=0;i<n;i++)
	{
		while(cmp>0&&st[i]!=tem[cmp])
			cmp=nex[cmp-1];
		if(st[i]==tem[cmp])
			cmp++;
		if(cmp==m)
			return 1;
	}
	return 0;
}
int main()
{
	int t,m;
	cin>>t;
	while(t--){
		cin>>m;
		scanf("%s",s);//作为母串,枚举子串
		for(int i=1;i<m;i++)
			scanf("%s",str[i]);
		memset(ans,0,sizeof(ans));
		ans[0]='z';
		int tail,head=0;
		for(tail=strlen(s)-1;tail>=2;tail--)//枚举匹配串终点
		{
			for(head=0;head<tail;head++)//枚举匹配串起点
			{
				int len=0,flag=1;//是否为所有串子串
				for(int i=head;i<=tail;i++)
				{
					temp[len++]=s[i];
				}
				temp[len]='\0';
				if(len<strlen(ans))//长度比当前答案小
						break;
				getnex(temp,len);
				for(int i=1;i<m;i++)
				{
					if(!kmp(temp,len,str[i],strlen(str[i])))//有一个匹配失败
					{
						flag=0;
						break;
					}
				}
				if(flag)
				{
					if(strlen(ans)<len||strcmp(temp,ans)<0)//长度大于ans,字典序
						strcpy(ans,temp);
				}
//				printf("flag=%d,head=%d,tail=%d,ans=%s,temp=%s\n",flag,head,tail,ans,temp);
			}
		}
		if(strlen(ans)<3)
			cout<<"no significant commonalities"<<endl;
		else
			cout<<ans<<endl;
	}
	return 0;
}
