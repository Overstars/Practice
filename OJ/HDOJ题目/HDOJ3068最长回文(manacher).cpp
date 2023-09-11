#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<map>
using namespace std;
#define PI 3.14159265358979323846
#define e  2.7182818284590452354
#define ln_2 0.69314718055994530942
#define ln_10 2.30258509299404568402
const int inf=0x3f3f3f3f;
/*
 *String:加'#'处理后的回文串
 *MaxR:最长回文半径对应的右端字符MaxRight
 *flag:最长回文半径对应的中心点下标
 *cnt[i]:以i为中心对应的回文半径
 *l:String长度
*/
const int maxlen=110005;
char str[maxlen],String[maxlen<<1];
int cnt[maxlen<<1];//记录处理后字符串i点最大回文半径
int Manacher(char s[],int len)//原字符串和串长
{
    int l=0;
    String[l++] = '$'; // 0下标存储为其他字符,防止越界
    String[l++] = '#';
    for(int i=0;i<len;i++)
	{
        String[l++]=s[i];
        String[l++]='#';
    }
    String[l]='\0'; // 空字符
    int MaxR=0;//最长回文半径对应的右端字符MaxRight
    int flag=0;//最长回文半径对应的中心点下标
    int ans=0;
    for(int i=0;i<l;i++)
	{
		if(i<MaxR)//i一定大于flag(在一开始及i赋值给flag时i==flag)
			cnt[i]=min(cnt[(flag<<1)-i],MaxR-i);//2*flag-i是i点关于flag的对称点,记为i'
		else//因为关于flag对称,当i+cnt[i']<=MaxR时,i两边cnt[i']个字符关于i对称,可以避免重复匹配。取min是因为i+cnt[i']有可能超出MaxR
			cnt[i]=1;//从头开始匹配
		while(String[i+cnt[i]]==String[i-cnt[i]])
			cnt[i]++;
		if(i+cnt[i]>MaxR)//新计算的回文串右端点位置大于MaxR
		{
			MaxR=i+cnt[i];//更新到达最右端点
			flag=i;
		}
		ans=max(ans,cnt[i]);
	}
	return ans-1;
}
int main()
{
	while(scanf("%s",str)==1)
		cout<<Manacher(str,strlen(str))<<endl;
	return 0;
}
