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
ll x[maxn],c[maxn],pur[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	int n;//����n�죬��ʼΪk
	ll minc=inf,cost=0,a,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	cin>>a;//һ������������ֵ
	for(int i=1;i<=n;i++)
		cin>>c[i];//��i�칺�����ϵĳɱ�
	bool flag=1;
	priority_queue<ll, vector<ll>, greater<ll> > QAQ;
	for(int i=1;i<=n;i++)
	{
		QAQ.push(c[i]);//����С����
		while(k<x[i]&&!QAQ.empty())
		{
			minc=QAQ.top();
			QAQ.pop();
			cost+=minc;//��������,�ҵ�֮ǰû�������˵�
			k+=a;
		}
		if(k<x[i])
		{
			flag=0;
			break;
		}
	}
	cout<<(flag?cost:-1)<<endl;
	return 0;
}
