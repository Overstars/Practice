#include<stdio.h>
#include<string.h>
int main(){
	char ch[14],s[14];
	int sum=0,num,i,mod,j;
	scanf("%s",ch);
	strcpy(s,ch);//拷贝一份储存正确结果
	for(i=0,j=1;i<11;i++){//注意下标
		if(ch[i]>='0'&&ch[i]<='9'){
			num=(int)(ch[i]-'0');
			sum+=num*j;
			j++;
		}
	}
	mod=sum%11;
	if(mod==10){
		s[12]='X';
	}
	else{
		s[12]=(char)(mod+'0');
	}
	if(strcmp(ch,s)==0)
		printf("Right");
	else
		printf("%s",s);
	return 0;
}
