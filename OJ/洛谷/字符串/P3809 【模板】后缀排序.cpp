#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=1e6+5;
int sa[MAXN],rak[MAXN],height[MAXN],tp[MAXN],tax[MAXN];
//sa[排名]=编号:第i名的后缀是从sa[i]开始(下标)
//rak[编号](a[i])=排名:第i号后缀串排名为rak[i]
//tp[i](b[i]):第二关键字为i的后缀串从tp[i]开始(下标)
//tax[i]:第一关键字为i的数有tax[i]个(基数排序时用的桶)
char s[MAXN];
int len,m;//len为s长度,m为基数排序的上界
void rsort(int a[],int b[])//a为第一关键字排名,b为第二关键字
{
	for(int i=0;i<=m;i++)//分配m个桶
		tax[i]=0;//桶清空
	for(int i=1;i<=len;i++)
		tax[a[i]]++;//每个数放进自己的桶
	for(int i=1;i<=m;i++)
		tax[i]+=tax[i-1];//每一后面的桶加上前面的桶
	for(int i=len;i>=1;i--)
		sa[tax[a[b[i]]]--]=b[i];
}
bool comp(int r[],int a,int b,int k)
{//通过二元组两个下标的比较，确定两个子串是否相同
    return r[a]==r[b]&&r[a+k]==r[b+k];
}
void get_sa(int a[],int b[])//a/b:指向rak与tp的指针
{
	for(int i=1;i<=len;i++)
		m=max(m,a[i]=s[i]-'0'),b[i]=i;
	rsort(a,b);//先对每个后缀串首个字符按字典序排序
	for(int p=0,j=1;p<len;j<<=1,m=p)//j为倍增长度
	{//Len条后缀串长度不同,一定能分出先后
		p=0;//p表示不同后缀串个数
		for(int i=1;i<=j;i++)//后j个后缀没有第二关键字,把它塞前面
			b[++p]=len-j+i;
		for(int i=1;i<=len;i++)
			if(sa[i]>j)
				b[++p]=sa[i]-j;
		rsort(a,b);//新的离散化,直到排名各不相同时结束
		swap(a,b);//交换指向rak与tp的指针
		a[sa[1]]=p=1;//第一名的第一关键字是1
        for(int i=2;i<=len;i++)//下一个与之前串相同则并列,否则排后面
			a[sa[i]]=comp(b,sa[i],sa[i-1],j)?p:++p;//本轮排名相近的两个子串
    }
}
void getheight()
{//height[i]:排名为 i 的后缀与排名为 i-1 的后缀串的 LCP
	for(int i=1;i<=len;i++)//根据sa求出rak(这一段自己加上去的)
		rak[sa[i]]=i;
	for(int i=1,j=0;i<=len;i++)
	{
		if(j)
			j--;
		while(s[i+j]==s[sa[rak[i]-1]+j])
			j++;
		height[rak[i]]=j;
	}
}
int main()
{
    scanf("%s",s+1);
    len=strlen(s+1);//还是正常的长度
    get_sa(rak,tp);
//    cout<<"sa:"<<endl;
    for(int i=1;i<=len;i++)
		printf("%d ",sa[i]);
}

