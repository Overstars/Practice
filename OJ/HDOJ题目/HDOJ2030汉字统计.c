/*输入文件首先包含一个整数n，表示测试实例的个数，然后是n段文本。
 对于每一段文本，输出其中的汉字的个数，每个测试实例的输出占一行。
[Hint:]从汉字机内码的特点考虑~
*解法：将汉字的国标码（2字节16位，每字节只使用低七位）2字节最高位设为1，作为汉字的机内码。
而补码的最高位作为符号位，也就是说，一个汉字的机内码从补码的角度来看相当于两个负数。 
*/
#include<stdio.h>
#include<string.h>
int main(void)
{
	int n;
	char str[10005];
	scanf("%d",&n);
	getchar();//换行符还是要处理一下的 
	while(n-->0){
		int i,count=0;
		fgets(str,10000,stdin);
		for(i=0;i<strlen(str);i++)
			if(str[i]<0)
				count++;
		printf("%d\n",count/2);
	}
	return 0;
}
