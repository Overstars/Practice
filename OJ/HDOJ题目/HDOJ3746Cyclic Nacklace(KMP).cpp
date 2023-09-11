#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[100005];
int nex[100005];
void getnex(int n)
{
	nex[0]=0;
	for(int i=1,j=0;i<n;i++){
//		j=nex[i-1];
		while(j>0&&s[i]!=s[j])
			j=nex[j-1];
		if(s[i]==s[j])
			j++;
		nex[i]=j;
	}
}
int main()//左端或右端添加最少字符,使字符串成为重复串
{
	int t;
	cin>>t;
	while(t--){
		scanf("%s",s);
		int len=strlen(s);
		getnex(len);
		int l=len-nex[len-1];//nex为最大公共子串
		if(len%l==0&&l!=len)//l是最小循环串
			printf("0\n");
		else if(l==len)//s的最大公共子串=0,整个重复一遍
			printf("%d\n",len);//可以和下面的分支合并的
		else
			printf("%d\n",l-nex[len-1]%l);
	}
	return 0;
}
//l一直为可能的最小重复串,是s去掉了后缀的最大公共子串剩下的那一部分
//当l>nex时,ans相当于补上了s结尾的l-nex个字符
//l<nex时,例如:abbabba,l=3,代表最小重复串abb
//更明显的例子s=abababa,nex=5,l=2(代表ab),因为最大公共子串nex存在,所以s从0到len-len%l那一部分,一直在循环l串。
//且结尾剩下的len%l个字符,也是l串的前len%l个字符
//所以printf("%d\n",l-nex[len-1]%l);换成l-len%l也是行得通的
