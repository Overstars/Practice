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
const int maxn = 2e6+10;
struct SuffixArray
{
    int s[maxn];      // ԭʼ�ַ����飨���һ���ַ�Ӧ������0����ǰ����ַ������0��
    int sa[maxn];     // ��׺����.�±�1:n-1��Ч
    int rak[maxn];    // ��������. rak[0]һ����n-1�������һ���ַ�.�±�1:n-1��Ч
    int height[maxn]; // height����.�±�2:n-1��Ч
    int t[maxn], t2[maxn], c[maxn]; // ��������
    int n; // �ַ�����,nΪch����+1
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
        for(int k = 1; k <= n; k <<= 1)
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
char ch[maxn];

int main()
{
	int len,bar,ans=0;
	while(~scanf("%s",ch))
	{
		bar=strlen(ch);
		ch[bar]='{';
		scanf("%s",ch+bar+1);
		len=strlen(ch);

		sa.clear();
		for(int i=0;i<len;i++)
			sa.s[i]=ch[i]-'a'+1;
		sa.s[len]=0;
		sa.n=len+1;
		sa.build_sa(30);
		sa.build_height();

		ans=0;
		for(int i=1;i<=len;i++)
			if(sa.height[i]>ans&&(ll)(sa.sa[i]-bar)*(sa.sa[i-1]-bar)<0)
				ans=sa.height[i];
//		for(int i=1;i<=len;i++)
//		{
//			cout<<"����="<<sa.rak[sa.sa[i]]<<",hei="<<sa.height[i]<<"\t:"<<ch+sa.sa[i]<<endl;
//		}
//		sa.debug();
		cout<<ans<<endl;
	}
	return 0;
}
