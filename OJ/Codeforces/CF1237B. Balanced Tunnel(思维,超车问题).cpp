#pragma G++ optimize("O2")
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<climits>
#include<cmath>
#include<iomanip>//�������,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<map>
//#define lowbit(x) ((x) & -(x))
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=100005;
//#define DEBUG
//bool cmp(const node &a,const node &b)
//{
//	return a.no<b.no;
//}
int a[maxn],b[maxn],c[maxn];
bool vis[maxn],rec[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	int n,cnt=0,M=0;//����O(n^2)����TLE
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];//��i���붴�ĳ�Ϊa[i]
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];//��i�������ĳ�Ϊb[i]
		c[b[i]]=i;//c[i]��ʾ���Ϊi�ĳ���c[i]������
	}
	for(int i=2;i<=n;i++)
	{
		M=max(M,c[a[i-1]]);
		if(c[a[i]]<M)
			cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
/*
 *n��С����ͨ�����
 *�������˳�������˳��,�ҳ��ж��ٳ��г�����Ϊ
 *ʱ��1s,����1e5m���������϶���ʱ
 *��������¼a[i]��Ӧ�ĳ���ʱ��c[i]
 *������a[i]ʱ,�������һ��������ı�a[i]��,�����ı�a[i]��
 *˵��a[i]���ڳ�����Ϊ
*/
