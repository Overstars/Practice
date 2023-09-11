//母函数求解
//处理问题：
//现在有m种面值的硬币，每一种的面值为a[i],数量为b[i]
//求能有多少种方法构成n元钱
#include<stdio.h>
#include<string.h>
 
int c1[1000],c2[1000];//c1[n]代表n元钱有多少种方法构成。
int a[45],b[45];
 
int main()
{
	int t,i,j,k,n,m,sum;//t组数据 
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		scanf("%d%d",&n,&m);//共修n学分，一共有m行 
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&a[i],&b[i]);//学分为a的课有b门 ，用a,b数组记录m组 
			sum=sum+a[i]*b[i];//计算总共的学分 
		}
		for(i=0;i<=sum;i++)//初始化数组,用排列组合来理解? 
		{
			c1[i]=0;//c1储存每一项系数 
			c2[i]=0;//c2储存每一项幂 
		}
		c1[0]=1;//
		for(i=1;i<=b[1];i++)
			c1[i*a[1]]=1;
		int len=a[1]*b[1];
		for(i=2;i<=m;i++)
		{
			for(j=0;j<=len;j++)
				for(k=0;k<=a[i]*b[i];k=k+a[i])
					c2[k+j]=c2[k+j]+c1[j];
			len=len+a[i]*b[i];
			for(j=0;j<=sum;j++)
			{
				c1[j]=c2[j];
				c2[j]=0;
			}
		}
		printf("%d\n",c1[n]);//输出幂为n那一项的系数 
	}
	return 0;
}
//--------------------- 
//作者：xieshimao 
//来源：CSDN 
//原文：https://blog.csdn.net/xieshimao/article/details/6667942 
//参考：https://blog.csdn.net/qq_41357771/article/details/83449481 
//版权声明：本文为博主原创文章，转载请附上博文链接！
