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
const int maxn = 100010;
struct SuffixArray
{
	//倍增算法 O(nlogn)
    int s[maxn];      // 原始字符数组（最后一个字符应必须是0，而前面的字符必须非0）
    int sa[maxn];     // 后缀数组.sa[0]一定是n-1，即最后一个字符0. 下标1:n-1有效
    int rak[maxn];    // 名次数组.rak[n-1]=0.下标0:n-2有效
    int height[maxn]; // height数组.下标1:n-1有效
    //sa[名次]=下标,rak[下标]=名次,height[i]=排名为i-1与i的公共前缀长度
    int t[maxn], t2[maxn], c[maxn]; // 辅助数组
    int n; // 字符个数(包括0),n为ch长度+1
    void clear()
    {
        n=0;
        memset(sa,0,sizeof(sa));
    }
    // m为最大字符值加1。调用之前需设置好s和n
    void build_sa(int m)
    {
        int i, *x = t, *y = t2;
        for(i = 0; i < m; i++) c[i]=0;
        for(i = 0; i < n; i++) c[x[i]=s[i]]++;
        for(i = 1; i < m; i++) c[i]+=c[i-1];
        for(i = n-1; i >= 0; i--) sa[--c[x[i]]]=i;
        /*for(int k = 1; k <= n; k <<= 1)
        {
            int p = 0;
            for(i = n-k; i < n; i++) y[p++] = i;
            for(i = 0; i < n; i++) if(sa[i] >= k) y[p++] = sa[i]-k;

            for(i = 0; i < m; i++) c[i] = 0;
            for(i = 0; i < n; i++) c[x[y[i]]]++;
            for(i = 1; i < m; i++) c[i] += c[i-1];
            for(i = n-1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];

            swap(x, y);
            p = 1;
            x[sa[0]] = 0;
            for(i = 1; i < n; i++)
                x[sa[i]] = y[sa[i-1]]==y[sa[i]] && y[sa[i-1]+k]==y[sa[i]+k] ? p-1 : p++;
            if(p >= n) break;
				m = p;
        }*/
		for(int j = 1, k = 1; k < n; j<<=1, m = k)
		{
			//j是当前字符串的长度,数组y保存的是对第二关键字排序的结果
			//第二关键字排序
			for(k = 0, i = n - j; i < n; ++i) y[k++] = i;//第二关键字为0的排在前面
			for(i = 0; i < n; ++i) if(sa[i] >= j) y[k++] = sa[i] - j;//长度为j的子串sa[i]应该是长度为2 * j的子串sa[i] - j的后缀（第二关键字）,对所有的长度为2 * j的子串根据第二关键字来排序
			for(i = 0; i < n; ++i) x[y[i]] = x[y[i]];//提取第一关键字
			//按第一关键字排序 (原理同对长度为1的字符串排序)
			for(i = 0; i < m; ++i) c[i] = 0;
			for(i = 0; i < n; ++i) c[x[y[i]]]++;
			for(i = 1; i < m; ++i) c[i] += c[i - 1];
			for(i = n - 1; i >= 0; --i) sa[--c[x[y[i]]]] = y[i];//按第一关键字,计算出了长度为2 * j的子串排名情况
			//此时数组x是长度为j的子串的排名情况,数组y仍是根据第二关键字排序后的结果
			//计算长度为2 * j的子串的排名情况,保存到数组x
			swap(x,y);
			for(x[sa[0]] = 0, i = k = 1; i < n; ++i)
				x[sa[i]] = (y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + j] == y[sa[i] + j]) ? k - 1 : k++;
			//若长度为2 * j的子串sa[i]与sa[i - 1]完全相同,则他们有相同的排名
		}
    }
    void build_height()
    {
        int i, j, k = 0;
        for(i = 0; i < n; i++)
			rak[sa[i]] = i;
        for(i = 0; i < n; i++)
        {
            if(k) k--;
            int j = sa[rak[i]-1];
            while(s[i+k] == s[j+k]) k++;
            height[rak[i]] = k;
        }
    }
    void debug()
	{
		for(int i = 1; i < n ; i ++)
		{
			printf("%d ", sa[i]);
			printf("%d\n", height[i]);
		}puts("");
	}
};

SuffixArray sa;
//char ch[maxn];
bool judge(int len,int n)//尝试的长度
{
	int M=sa.sa[0],m=sa.sa[0];//sa[排名]=下标
	for(int i=1;i<n;i++)
	{
		if(sa.height[i]>=len)//出现了公共长度大于mid的后缀串,判断是否重叠
			M=max(M,sa.sa[i]),m=min(m,sa.sa[i]);//尽量使两段分的比较远,能大于len
		else//在下一区间重新开始寻找公共长>=len的两段后缀串
			M=sa.sa[i],m=sa.sa[i];
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
//		sa.clear();
		if(n==1)
		{
			puts("0");
			continue;
		}
		maxi=ans=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&sa.s[i]);
			if(i){
				sa.s[i-1]=sa.s[i]-sa.s[i-1]+88;
				maxi=max(maxi,sa.s[i-1]);
			}
		}
		sa.s[n-1]=0;
		sa.n=n;
		sa.build_sa(maxi+1);
		sa.build_height();
		int left=0,right=n-1,mid;
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

