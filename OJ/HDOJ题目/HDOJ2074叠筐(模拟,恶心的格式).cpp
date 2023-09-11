#include<cstdio>
#include<iostream>
using namespace std;
int main(void)
{
	int n,i,j,cnt,flag=0,flag2=0;
	char c1,c2,temp;
	while(scanf("%d %c %c",&n,&c1,&c2)==3){
		if(flag2){
			cout<<endl;
		}
		flag2=1;
		if(n==1){
			cout<<c1<<endl;
			continue;
		}
		if(flag==0&&((n-1)/2)%2==0){//N一定为奇数,求出套的层数
			temp=c1;
			c1=c2;
			c2=temp;
			flag=1;
		}
		cnt=0;
		for(i=0;i<n;i++){
			if(i==0||i==n-1){//第一行和最后一行
				for(j=0;j<n;j++){
					if((i==0&&j==0)||(i==n-1&&j==0)||(i==n-1&&j==n-1)||(i==0&&j==n-1)){
						cout<<' ';
					}
					else if(n%2==1)
						cout<<c2;
					else
						cout<<c1;
				}
			}
			else{//中间的n-2行
				for(j=0;j<cnt;j++){
					if(j%2)
						cout<<c1;
					else
						cout<<c2;
				}
				for(;j<n-cnt;j++)
					if(i%2)
						cout<<c1;
					else
						cout<<c2;
				for(;j<n;j++)
					if(j%2)
						cout<<c1;
					else
						cout<<c2;
			}
			cout<<endl;
			if(i<n/2)
				cnt++;
			else
				cnt--;
		}
		flag=0;
	}
	return 0;
}
// 0123456789
//0 AAAAAAAAA
//1ABBBBBBBBBA
//2ABAAAAAAABA
//3ABABBBBBABA
//4ABABAAABABA
//5ABABABABABA
//6ABABAAABABA
//7ABABBBBBABA
//8ABAAAAAAABA
//9ABBBBBBBBBA
//  AAAAAAAAA

// 0123456789
//0 AAAAAAAAA
//1ABBBBBBBBBA
//2ABAAAAAAABA
//3ABABBBBBABA
//4ABABAAABABA
//5ABABABABABA
//6ABABAAABABA
//7ABABBBBBABA
//8ABAAAAAAABA
//9ABBBBBBBBBA
//  AAAAAAAAA
