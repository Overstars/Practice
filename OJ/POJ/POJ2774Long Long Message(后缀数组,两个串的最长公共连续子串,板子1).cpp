#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e6+10;
int sa[MAXN],rak[MAXN],height[MAXN],tp[MAXN],tax[MAXN];
//sa[排名]=编号:第i名的后缀是从sa[i]开始(下标)
//rak[编号](a[i])=排名:第i号后缀串排名为rak[i]
//height[i]:排名i-1与i的连个后缀串的最长公共前缀长度
//tp[i](b[i]):第二关键字为i的后缀串从tp[i]开始(下标)
//tax[i]:第一关键字为i的数有tax[i]个(基数排序时用的桶)
char str[MAXN];
int len,m;//len为s长度,m为基数排序的上界
void rsort(int a[],int b[])//a为第一关键字排名(上一次的rank),b为第二关键字排名i的位置
{
	for(int i=0;i<=m;i++)//分配m个桶
		tax[i]=0;//桶清空
	for(int i=1;i<=len;i++)
		tax[a[i]]++;//每个第一关键字放进自己的桶
	for(int i=1;i<=m;i++)
		tax[i]+=tax[i-1];//前缀和:每一后面的桶加上前面的桶,快速的定位出每个位置应有的排名
//前缀和可以统计比当前名次小的后缀有多少个
	for(int i=len;i>=1;i--)
		sa[tax[a[b[i]]]--]=b[i];//计算新的排名
}
//假设已经得到了w长度的排名，要更新2w长度的排名
//sa[i]：长度为w的后缀中，排名为i的后缀的位置
//a[i]:长度为w的后缀中，从第i个位置开始的后缀的排名(a[位置]=排名)
//b[i]:长度为2w的后缀中，第二关键字排名为i的后缀的位置(b[排名]=位置)
//i从大到小枚举第二关键字b[i],再用a[i]定位到第一关键字排名
//第一关键字相对顺序不变,用b尽量确定a相同的后缀串的相对位置
bool comp(int r[],int a,int b,int k)
{//双关键字离散,确定两个子串是否相同
	return r[a]==r[b]&&r[a+k]==r[b+k];
}//s[i:i+2w]串的排名由上一轮的s[i:i+w]与s[i+w:i+2w]排名综合得出
//当轮s[i:i+w]的排名储存在上轮生成的a[i]上
//返回true说明s[i:i+w]
void get_sa(char s[],int a[],int b[])//s:指向str的指针,a/b:指向rak与tp的指针
{
	for(int i=1;i<=len;i++)
		m=max(m,a[i]=s[i]-'0'),b[i]=i;
	rsort(a,b);//先对每个后缀串首个字符按字典序排序
	for(int p=0,j=1;p<len;j<<=1,m=p)//j为倍增长度
	{//Len条后缀串长度不同,一定能分出先后
		p=0;//这里p是计数器
		//开始对第二关键字进行排序,b[排名]=位置
		for(int i=1;i<=j;i++)//后j个后缀没有第二关键字,把它塞前面
			b[++p]=len-j+i;
		for(int i=1;i<=len;i++)//sa[i]:上一轮排名的结果
			if(sa[i]>j)//比j长的后缀串有第二关键字
				b[++p]=sa[i]-j;//1.按照上轮排好的顺序 2.
		//第二关键字排序结束
		rsort(a,b);//新的离散化,直到排名各不相同时跳出循环
		swap(a,b);//这里b数组没用,而且要使用a更新下一轮的a
		//此时a将储存下一轮第一关键字排名,b是本轮第一关键字排名
		a[sa[1]]=p=1;//第一名的第一关键字是1,p表示不同后缀串个数
		for(int i=2;i<=len;i++)//当前串与之前串相同则并列,否则排后面
			a[sa[i]]=comp(b,sa[i],sa[i-1],j)?p:++p;//本轮排名相近的两个子串
    }//a[位置]=下一轮第一关键字排名,b[位置]=本轮第一关键字排名,sa[排名]=位置

}
void getheight(char s[])
{//height[i]:排名为 i 的后缀与排名为 i-1 的后缀串的 LCP
	for(int i=1;i<=len;i++)//根据sa求出rak(这一段自己加上去的)
		rak[sa[i]]=i;
	for(int i=1,j=0;i<=len;i++)
	{
		if(j)
			j--;
		while(s[i+j]==s[sa[rak[i]-1]+j])//
			j++;
		height[rak[i]]=j;
	}
}
int main()
{
    while(~scanf("%s",str+1))
	{
		int ans=0,bar;
		bar=strlen(str+1)+1;
		str[bar]='{';
		scanf("%s",str+bar+1);
		len=strlen(str+1);
		get_sa(str,rak,tp);
		getheight(str);
//		for(int i=1;i<=len;i++)
//		{
//			printf("%d ",height[i]);
//			if(i%5==0)
//				printf("\n");
//		}
//		printf("bar=%d,len=%d\n",bar,len);
		for(int i=1;i<=len;i++)
			if(height[i]>ans&&(ll)(sa[i]-bar)*(sa[i-1]-bar)<0)
				ans=height[i];
//		for(int i=1;i<=len;i++)
//		{
//			cout<<"排名="<<rak[sa[i]]<<",hei="<<height[i]<<"\t:"<<str+sa[i]<<endl;
//		}
		cout<<ans<<endl;
	}
	return 0;
}
