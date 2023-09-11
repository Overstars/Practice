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
{//�����㷨 O(nlogn)
	int n;//����ĩβ0���ڵ��ַ���
	int Rank[MAXN], height[MAXN], sa[MAXN], r[MAXN];
	//rnk��0��ʼ
	//sa��1��ʼ,��Ϊ���һ���ַ�(��С��)���ڵ�0λ
	//height��1��ʼ,��Ϊ��ʾ����sa[i - 1]��sa[i]
	int wa[MAXN], wb[MAXN], wv[MAXN], ws_[MAXN];
	//Suffix�����Ĳ���m�����ַ������ַ���ȡֵ��Χ,�ǻ��������һ������,���ԭ���ж�����ĸ����ֱ��ȡ128,���ԭ���б����������Ļ�,��m����ȡ������������1��ֵ
	//��������ַ�������r������,��r[0]��r[n-1]������Ϊn
	//Ϊ�˷���Ƚϴ�С,�������ַ����������һ���ַ�,����ַ�û����ǰ����ַ��г��ֹ�,���ұ�ǰ����ַ���ҪС
	//ͬ��,Ϊ�˺��������ķ���,Լ����r[n-1]�����е�r[i]������0,r[n-1]=0
	//����������,�������sa������,��sa[0]��sa[n-1],sa[0]=n-1
	void Suffix(int m)
	{
		int i, j, k, *x = wa, *y = wb, *t;
		//�Գ���Ϊ1���ַ�������
		//һ����˵,���ַ�������Ŀ��,r�����ֵ����ܴ�,��������ʹ���˻�������
		//���r�����ֵ�ܴ�,��ô����δ���ĳɿ�������
		for(i = 0; i < m; ++i) ws_[i] = 0;
		for(i = 0; i < n; ++i) ws_[x[i] = r[i]]++;//ͳ���ַ��ĸ���
		for(i = 1; i < m; ++i) ws_[i] += ws_[i - 1];//ͳ�Ʋ������ַ�i���ַ�����
		for(i = n - 1; i >= 0; --i) sa[--ws_[x[i]]] = i;//�����ַ�����
		//��������
		//x���鱣���ֵ�൱����rankֵ
		for(j = 1, k = 1; k < n; j<<=1, m = k)
		{
			//j�ǵ�ǰ�ַ����ĳ���,����y������ǶԵڶ��ؼ�������Ľ��
			//�ڶ��ؼ�������
			for(k = 0, i = n - j; i < n; ++i) y[k++] = i;//�ڶ��ؼ���Ϊ0������ǰ��
			for(i = 0; i < n; ++i) if(sa[i] >= j) y[k++] = sa[i] - j;//����Ϊj���Ӵ�sa[i]Ӧ���ǳ���Ϊ2 * j���Ӵ�sa[i] - j�ĺ�׺���ڶ��ؼ��֣�,�����еĳ���Ϊ2 * j���Ӵ����ݵڶ��ؼ���������
			for(i = 0; i < n; ++i) wv[i] = x[y[i]];//��ȡ��һ�ؼ���
			//����һ�ؼ������� (ԭ��ͬ�Գ���Ϊ1���ַ�������)
			for(i = 0; i < m; ++i) ws_[i] = 0;
			for(i = 0; i < n; ++i) ws_[wv[i]]++;
			for(i = 1; i < m; ++i) ws_[i] += ws_[i - 1];
			for(i = n - 1; i >= 0; --i) sa[--ws_[wv[i]]] = y[i];//����һ�ؼ���,������˳���Ϊ2 * j���Ӵ��������
			//��ʱ����x�ǳ���Ϊj���Ӵ����������,����y���Ǹ��ݵڶ��ؼ��������Ľ��
			//���㳤��Ϊ2 * j���Ӵ����������,���浽����x
			t = x;
			x = y;
			y = t;
			for(x[sa[0]] = 0, i = k = 1; i < n; ++i)
				x[sa[i]] = (y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + j] == y[sa[i] + j]) ? k - 1 : k++;
			//������Ϊ2 * j���Ӵ�sa[i]��sa[i - 1]��ȫ��ͬ,����������ͬ������
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
    	printf(" ���� �±�  height  ��׺��\n");
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
