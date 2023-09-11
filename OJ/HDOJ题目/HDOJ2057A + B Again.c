#include<stdio.h>
#include<string.h>
char lib[17]="0123456789ABCDEF";
void show(long long n);
long long trans(char s[]);
long long pow1(long long a,long long n);
int serch(char c);
int main(void)
{
	char s1[30],s2[30];
	while(scanf("%s %s",s1,s2)==2){
		long long a,b,ans;
		a=trans(s1);
		b=trans(s2);
		ans=a+b;
//		printf("a=%lld,b=%lld,ans=%lld\n",a,b,ans);
		if(ans<0){
			putchar('-');
			ans=-ans;
		}
//		if(ans==0)
//			putchar('0');
//		else
			show(ans);
		putchar('\n');
	}
	return 0;
}
void show(long long n)
{
//	if(n==0)
//		return;
	if(0<=n&&n<=16){
		printf("%c",lib[n]);
		return;
	}
	else{
		show(n/16);
		putchar(lib[n%16]);
	}
}
long long trans(char s[])
{
	long long ret=0;
	if(s[0]=='+'){
		long long len=strlen(s),i=0;
		for(i=0;i<len-1;i++){
			ret+=serch(s[len-i-1])*pow1(16,i);
		}
		return ret;
	}
	else if(s[0]=='-'){
		long long len=strlen(s),i=0;
		for(i=0;i<len-1;i++){
			ret+=serch(s[len-i-1])*pow1(16,i);
		}
		return -ret;
	}
	else{
		long long len=strlen(s),i=0;
		for(i=0;i<len;i++){
			ret+=serch(s[len-i-1])*pow1(16,i);
		}
		return ret;
	}
}
long long pow1(long long a,long long n)
{
	if(n==0)
		return 1;
	if(n==1)
		return a;
	else if(n%2==0)
		return pow1(a*a,n/2);
	else
		return pow1(a*a,n/2)*a;
}
int serch(char c)
{
	int i;
	for(i=0;i<17;i++)
		if(lib[i]==c)
			return i;
}
