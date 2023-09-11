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
//const int MAXN = 100010;
const int maxn =100010;
struct Suffix_Array
{//�����㷨�����׺����,���Ӷ�O(nlogn)
	int s[maxn];//�洢�������ַ�
	int c[maxn], sa[maxn], rank[maxn], height[maxn];
	int t[maxn], t2[maxn];
	void build_sa(int m, int n)
	{ //nΪ�ַ����ĳ���,�ַ�����ֵΪ0~m-1
		n++;
		int *x = t, *y = t2;
		//��������
		for (int i = 0; i < m; i++) c[i] = 0;
		for (int i = 0; i < n; i++) c[x[i] = s[i]]++;
		for (int i = 1; i < m; i++) c[i] += c[i - 1];
		for (int i = n - 1; ~i; i--) sa[--c[x[i]]] = i;
		for (int k = 1; k <= n; k <<= 1)
		{ //ֱ������sa��������ڶ��ؼ���
			int p = 0;
			for(int i = n - k; i < n; i++)
				y[p++] = i;
			for (int i = 0; i < n; i++)
				if (sa[i] >= k)
					y[p++] = sa[i] - k;
				//���������һ�ؼ���
			for (int i = 0; i < m; i++) c[i] = 0;
			for (int i = 0; i < n; i++) c[x[y[i]]]++;
			for (int i = 0; i < m; i++) c[i] += c[i - 1];
			for (int i = n - 1; ~i; i--) sa[--c[x[y[i]]]] = y[i];
			//����sa��y��������µ�x����
			swap(x, y);
			p = 1;
			x[sa[0]] = 0;
			for (int i = 1; i < n; i++)
				x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
			if (p >= n) break; //�Ժ�ʹ����������saҲ����ı䣬�Ƴ�
				m = p; //�´λ�����������ֵ
		}
		n--;
		int k = 0;
		for (int i = 0; i <= n; i++) rank[sa[i]] = i;
		for (int i = 0; i < n; i++)
		{
			if (k) k--;
			int j = sa[rank[i] - 1];
			while (s[i + k] == s[j + k]) k++;
			height[rank[i]] = k;
		}
	}
	void debug(int n)
    {
    	printf(" ���� �±�  height  ��׺��\n");
    	for(int i=0;i<n;i++)
		{
			printf("%5d%5d%5d     ",i,sa[i],height[i]);
			for(int j=sa[i];j<n;j++)
			{
				printf("%-3d ",c[j]);
			}
			printf("\n");
		}
    }
	int dp[maxn][30];
	void initrmq(int n)
	{
		for (int i = 1; i <= n; i++)
			dp[i][0] = height[i];
		for (int j = 1; (1 << j) <= n; j++)
			for (int i = 1; i + (1 << j) - 1 <= n; i++)
				dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
	}
//	int rmq(int l, int r)
//	{
//		int k = 31 - __builtin_clz(r - l + 1);
//		return min(dp[l][k], dp[r - (1 << k) + 1][k]);
//	}
//	int lcp(int a, int b)
//	{ // ��������׺�������ǰ׺
//		a = rank[a], b = rank[b];
//		if (a > b) swap(a, b);
//		return rmq(a + 1, b);
//	}
} sa;

//char ch[maxn];
bool judge(int len,int n)//���Եĳ���
{
	int M=sa.sa[0],m=sa.sa[0];//sa[����]=�±�
	for(int i=1;i<n;i++)
	{
		if(sa.height[i]>=len)//�����˹������ȴ���mid�ĺ�׺��,�ж��Ƿ��ص�
			M=max(M,sa.sa[i]),m=min(m,sa.sa[i]);//����ʹ���ηֵıȽ�Զ,�ܴ���len
		else//����һ�������¿�ʼѰ�ҹ�����>=len�����κ�׺��
			M=m=sa.sa[i];
		if(M-m>len)//�����ڵĻ�,��ԭ�������ص�
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
			scanf("%d",&sa.s[i]);
			if(i){
				sa.s[i-1]=sa.s[i]-sa.s[i-1]+88;
				maxi=max(maxi,sa.s[i-1]);
			}
		}
		sa.s[--n]=0;
		sa.build_sa(maxi+1,n);
//		sa.debug(n);
		int left=0,right=n,mid;
		while(left<=right)
		{
			mid=(left+right)>>1;
			if(judge(mid,n+1))
				left=mid+1,ans=max(ans,mid);//�ڳ�����������Ҹ��Ž�
			else
				right=mid-1;
//			printf("l=%d,r=%d,ans=%d\n",left,right,ans);
		}
		if(ans>=4)
			cout<<ans+1<<endl;//��¼��ֵ,Ҫ+1
		else
			cout<<0<<endl;
	}
	return 0;
}
