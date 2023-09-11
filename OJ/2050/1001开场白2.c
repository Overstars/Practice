#include<stdio.h>
#include<string.h>
int main(void)
{
	int n,flag,count;
	char ch,ch2[4];
	scanf("%d",&n);
	getchar();
	while(n-->0){
		flag=1;
		ch=getchar();
		count=1;
		while(ch!='\n'){
			if((count==1&&ch=='2')||(count==2&&ch=='0')||(count==3&&ch=='5')||(count==4&&ch=='0'))
			{
				ch2[count-1]=ch;
				if(count==4)
					count=0;
				count++;
			}
			else{
				flag=0;
				break;
			}
			if((ch=getchar())!='\n'&&count==1)
				ch2[0]=ch2[1]=ch2[2]=ch2[3]='1';
		}
		if(flag==1&&ch2[0]=='2'&&ch2[1]=='0'&&ch2[2]=='5'&&ch2[3]=='0')
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
