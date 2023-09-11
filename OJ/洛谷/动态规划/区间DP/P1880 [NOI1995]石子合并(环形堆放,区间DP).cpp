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
#include<map>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=205;
int ma[maxn][maxn],mi[maxn][maxn],sum[maxn];
//#define DEBUG
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	int n,tem,len;
	cin>>n;
	len=(n<<1)-1;
	for(int i=1;i<=n;i++)
	{
		cin>>sum[i];
		sum[n+i]=sum[i];
	}
	for(int i=1;i<=len;i++)
	{
		sum[i]+=sum[i-1];//ǰ׺��
	}
	for(int l=2;l<=len;l++)//ö�ٸ��ǳ���
	{
		for(int i=1;i<=len-l+1;i++)//ö�����
		{
			int j=i+l-1;//ö���յ�
			mi[i][j]=inf;//��ʼ��
			int tem=sum[j]-sum[i-1];//i��jʯ��������
			for(int k=i;k<j;k++)//ö���м�ָ��
			{
				mi[i][j]=min(mi[i][j],mi[i][k]+mi[k+1][j]+tem);
				ma[i][j]=max(ma[i][j],ma[i][k]+ma[k+1][j]+tem);
			}
		}
	}
	int ans1=inf,ans2=-inf;
	for(int i=1;i<=n;i++)//��ģΪn
	{
		ans1=min(ans1,mi[i][n+i-1]);
		ans2=max(ans2,ma[i][n+i-1]);
	}
	cout<<ans1<<endl;
	cout<<ans2<<endl;
	return 0;
}
