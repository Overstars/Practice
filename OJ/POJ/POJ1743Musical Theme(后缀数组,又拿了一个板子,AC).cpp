#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int MAXN = 100010;
struct SuffixArray
{//倍增算法 O(nlogn)
	int n;//包括末尾0在内的字符数
	int Rank[MAXN], height[MAXN], sa[MAXN], r[MAXN];
	//rnk从0开始
	//sa从1开始,因为最后一个字符(最小的)排在第0位
	//height从1开始,因为表示的是sa[i - 1]和sa[i]
	int wa[MAXN], wb[MAXN], wv[MAXN], ws_[MAXN];
	//Suffix函数的参数m代表字符串中字符的取值范围,是基数排序的一个参数,如果原序列都是字母可以直接取128,如果原序列本身都是整数的话,则m可以取比最大的整数大1的值
	//待排序的字符串放在r数组中,从r[0]到r[n-1]，长度为n
	//为了方便比较大小,可以在字符串后面添加一个字符,这个字符没有在前面的字符中出现过,而且比前面的字符都要小
	//同上,为了函数操作的方便,约定除r[n-1]外所有的r[i]都大于0,r[n-1]=0
	//函数结束后,结果放在sa数组中,从sa[0]到sa[n-1],sa[0]=n-1
	void Suffix(int m)
	{
		int i, j, k, *x = wa, *y = wb, *t;
		//对长度为1的字符串排序
		//一般来说,在字符串的题目中,r的最大值不会很大,所以这里使用了基数排序
		//如果r的最大值很大,那么把这段代码改成快速排序
		for(i = 0; i < m; ++i) ws_[i] = 0;
		for(i = 0; i < n; ++i) ws_[x[i] = r[i]]++;//统计字符的个数
		for(i = 1; i < m; ++i) ws_[i] += ws_[i - 1];//统计不大于字符i的字符个数
		for(i = n - 1; i >= 0; --i) sa[--ws_[x[i]]] = i;//计算字符排名
		//基数排序
		//x数组保存的值相当于是rank值
		for(j = 1, k = 1; k < n; j<<=1, m = k)
		{
			//j是当前字符串的长度,数组y保存的是对第二关键字排序的结果
			//第二关键字排序
			for(k = 0, i = n - j; i < n; ++i) y[k++] = i;//第二关键字为0的排在前面
			for(i = 0; i < n; ++i) if(sa[i] >= j) y[k++] = sa[i] - j;//长度为j的子串sa[i]应该是长度为2 * j的子串sa[i] - j的后缀（第二关键字）,对所有的长度为2 * j的子串根据第二关键字来排序
			for(i = 0; i < n; ++i) wv[i] = x[y[i]];//提取第一关键字
			//按第一关键字排序 (原理同对长度为1的字符串排序)
			for(i = 0; i < m; ++i) ws_[i] = 0;
			for(i = 0; i < n; ++i) ws_[wv[i]]++;
			for(i = 1; i < m; ++i) ws_[i] += ws_[i - 1];
			for(i = n - 1; i >= 0; --i) sa[--ws_[wv[i]]] = y[i];//按第一关键字,计算出了长度为2 * j的子串排名情况
			//此时数组x是长度为j的子串的排名情况,数组y仍是根据第二关键字排序后的结果
			//计算长度为2 * j的子串的排名情况,保存到数组x
			t = x;
			x = y;
			y = t;
			for(x[sa[0]] = 0, i = k = 1; i < n; ++i)
				x[sa[i]] = (y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + j] == y[sa[i] + j]) ? k - 1 : k++;
			//若长度为2 * j的子串sa[i]与sa[i - 1]完全相同,则他们有相同的排名
		}
	}
	void build_height()
    {
        int i, j, k = 0;
        for(i = 0; i < n; i++)
			Rank[sa[i]] = i;
        for(i = 0; i < n; i++)
        {
            if(k) k--;
            int j = sa[Rank[i]-1];
            while(r[i+k] == r[j+k]) k++;
            height[Rank[i]] = k;
        }
    }
    void debug()
    {
    	printf(" 名次 下标  height  后缀串\n");
    	for(int i=0;i<n;i++)
		{
			printf("%5d%5d%5d     ",i,sa[i],height[i]);
			for(int j=sa[i];j<n;j++)
			{
				printf("%-3d ",r[j]);
			}
			printf("\n");
		}
    }
} sa;
//char ch[maxn];
bool judge(int len,int n)//尝试的长度
{
	int M=sa.sa[0],m=sa.sa[0];//sa[排名]=下标
	for(int i=1;i<n;i++)
	{
		if(sa.height[i]>=len)//出现了公共长度大于mid的后缀串,判断是否重叠
			M=max(M,sa.sa[i]),m=min(m,sa.sa[i]);//尽量使两段分的比较远,能大于len
		else//在下一区间重新开始寻找公共长>=len的两段后缀串
			M=m=sa.sa[i];
		if(M-m>len)//若等于的话,还原后会出现重叠
			return 1;
	}
	return 0;
}
int main()
{
	int ans=0,n,maxi;
	while(cin>>n&&n)
	{
		if(n==1)
		{
			scanf("%d",&maxi);
			puts("0");
			continue;
		}
		maxi=ans=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&sa.r[i]);
			if(i){
				sa.r[i-1]=sa.r[i]-sa.r[i-1]+88;
				maxi=max(maxi,sa.r[i-1]);
			}
		}
		sa.r[n-1]=0;
		sa.n=n;
		sa.Suffix(maxi+1);
		sa.build_height();
//		sa.getheight(n-1);
//		sa.debug();
		int left=0,right=n,mid;
		while(left<=right)
		{
			mid=(left+right)>>1;
			if(judge(mid,n))
				left=mid+1,ans=max(ans,mid);//在成立的情况下找更优解
			else
				right=mid-1;
//			printf("l=%d,r=%d,ans=%d\n",left,right,ans);
		}
		if(ans>=4)
			cout<<ans+1<<endl;//记录差值,要+1
		else
			cout<<0<<endl;
	}
	return 0;
}
