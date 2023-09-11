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
	//�����㷨 O(nlogn)
    int s[maxn];      // ԭʼ�ַ����飨���һ���ַ�Ӧ������0����ǰ����ַ������0��
    int sa[maxn];     // ��׺����.sa[0]һ����n-1�������һ���ַ�0. �±�1:n-1��Ч
    int rak[maxn];    // ��������.rak[n-1]=0.�±�0:n-2��Ч
    int height[maxn]; // height����.�±�1:n-1��Ч
    //sa[����]=�±�,rak[�±�]=����,height[i]=����Ϊi-1��i�Ĺ���ǰ׺����
    int t[maxn], t2[maxn], c[maxn]; // ��������
    int n; // �ַ�����(����0),nΪch����+1
    void clear()
    {
        n=0;
        memset(sa,0,sizeof(sa));
    }
    // mΪ����ַ�ֵ��1������֮ǰ�����ú�s��n
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
			//j�ǵ�ǰ�ַ����ĳ���,����y������ǶԵڶ��ؼ�������Ľ��
			//�ڶ��ؼ�������
			for(k = 0, i = n - j; i < n; ++i) y[k++] = i;//�ڶ��ؼ���Ϊ0������ǰ��
			for(i = 0; i < n; ++i) if(sa[i] >= j) y[k++] = sa[i] - j;//����Ϊj���Ӵ�sa[i]Ӧ���ǳ���Ϊ2 * j���Ӵ�sa[i] - j�ĺ�׺���ڶ��ؼ��֣�,�����еĳ���Ϊ2 * j���Ӵ����ݵڶ��ؼ���������
			for(i = 0; i < n; ++i) x[y[i]] = x[y[i]];//��ȡ��һ�ؼ���
			//����һ�ؼ������� (ԭ��ͬ�Գ���Ϊ1���ַ�������)
			for(i = 0; i < m; ++i) c[i] = 0;
			for(i = 0; i < n; ++i) c[x[y[i]]]++;
			for(i = 1; i < m; ++i) c[i] += c[i - 1];
			for(i = n - 1; i >= 0; --i) sa[--c[x[y[i]]]] = y[i];//����һ�ؼ���,������˳���Ϊ2 * j���Ӵ��������
			//��ʱ����x�ǳ���Ϊj���Ӵ����������,����y���Ǹ��ݵڶ��ؼ��������Ľ��
			//���㳤��Ϊ2 * j���Ӵ����������,���浽����x
			swap(x,y);
			for(x[sa[0]] = 0, i = k = 1; i < n; ++i)
				x[sa[i]] = (y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + j] == y[sa[i] + j]) ? k - 1 : k++;
			//������Ϊ2 * j���Ӵ�sa[i]��sa[i - 1]��ȫ��ͬ,����������ͬ������
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
bool judge(int len,int n)//���Եĳ���
{
	int M=sa.sa[0],m=sa.sa[0];//sa[����]=�±�
	for(int i=1;i<n;i++)
	{
		if(sa.height[i]>=len)//�����˹������ȴ���mid�ĺ�׺��,�ж��Ƿ��ص�
			M=max(M,sa.sa[i]),m=min(m,sa.sa[i]);//����ʹ���ηֵıȽ�Զ,�ܴ���len
		else//����һ�������¿�ʼѰ�ҹ�����>=len�����κ�׺��
			M=sa.sa[i],m=sa.sa[i];
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

