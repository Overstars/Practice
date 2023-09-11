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
void getnex(char *st,int n)//�����ַ���,����
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
bool kmp(char *tem,int m,char *st,int n)//�Ӵ�,�Ӵ�����,ƥ��ģ�崮,ģ�崮����
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
		scanf("%s",s);//��Ϊĸ��,ö���Ӵ�
		for(int i=1;i<m;i++)
			scanf("%s",str[i]);
		memset(ans,0,sizeof(ans));
		ans[0]='z';
		int tail,head=0;
		for(tail=strlen(s)-1;tail>=2;tail--)//ö��ƥ�䴮�յ�
		{
			for(head=0;head<tail;head++)//ö��ƥ�䴮���
			{
				int len=0,flag=1;//�Ƿ�Ϊ���д��Ӵ�
				for(int i=head;i<=tail;i++)
				{
					temp[len++]=s[i];
				}
				temp[len]='\0';
				if(len<strlen(ans))//���ȱȵ�ǰ��С
						break;
				getnex(temp,len);
				for(int i=1;i<m;i++)
				{
					if(!kmp(temp,len,str[i],strlen(str[i])))//��һ��ƥ��ʧ��
					{
						flag=0;
						break;
					}
				}
				if(flag)
				{
					if(strlen(ans)<len||strcmp(temp,ans)<0)//���ȴ���ans,�ֵ���
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
