#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
bool jud(int n);
int p(int a,int b);
int main()
{
	int n;
	while(cin>>n)
		cout<<jud(n)<<endl;
}
bool jud(int n)//将要判断的数传入
{
	int temp,head,tail,cnt=0,i;
	while(n>=10){//当n只有一位,不用判断
		tail=n%10;
		n/=10;//去掉位一位
		temp=n;
		cnt=0;
		while(temp>=10){
			cnt++;
			temp/=10;//n此时为cnt+1位,temp为第一位
		}
		head=temp;
		if(head!=tail)
			return 0;
		n%=p(10,cnt);//去掉头一位
	}
	return 1;
}
int p(int a,int b)//a的b次幂
{
	int sum = 1;
	while(b>0) {
		if(b%2==1)
			sum=sum*a;
		b/=2;
		a=a*a;
	}
	return sum;
}
