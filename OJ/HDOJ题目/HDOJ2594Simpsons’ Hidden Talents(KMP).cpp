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
const int inf=0x3f3f3f3f;
char a[50005],b[50005],cat[100005];
int nex[100005];
int maxn;
void getnex(char *s,int n)
{
	nex[0]=0;
	for(int i=1,j=0;i<n;i++)
	{
		while(j>0&&s[i]!=s[j])
			j=nex[j-1];
		if(s[i]==s[j])
			j++;
		nex[i]=j;
//		maxn=max(maxn,nex[i]);
	}
}
int main()
{
	while(scanf("%s%s",a,b)==2){
		strcpy(cat,a);
		strcat(cat,b);
		int lena=strlen(a),lenb=strlen(b);
		getnex(cat,strlen(cat));
		maxn=nex[strlen(cat)-1];
		if(maxn<lena&&maxn<lenb){
			for(int i=0;i<maxn;i++){
				putchar(a[i]);
				if(i==maxn-1)
					putchar(' ');
			}
			printf("%d\n",maxn);
		}
		else{
			if(lena>lenb)
				printf("%s ",b);
			else
				printf("%s ",a);
			cout<<min(lena,lenb)<<endl;
		}
	}
	return 0;
}
