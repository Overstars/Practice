#include<stdio.h>
#include<string.h>
int main(void)
{
	int n,flag,count,count2;
	char ch,ch2[4];
	scanf("%d",&n);
	getchar();
	while(n-->0){
		flag=1;
		count=1;
		count2=0;
		while((ch=getchar())!='\n'){
			if((count==1&&ch=='2')||(count==2&&ch=='0')||(count==3&&ch=='5')||(count==4&&ch=='0'))
			{
				if(count==4)
					count=0;
				count++;
			}
			else{
				flag=0;
				break;
			}
			count2++;
		}
		if(flag==1&&count==1&&count2!=0)
			printf("Yes\n");
		else
			printf("No\n");
		while(ch!='\n'){//处理剩下的字符 
			ch=getchar();
		}
	}
	return 0;
}
