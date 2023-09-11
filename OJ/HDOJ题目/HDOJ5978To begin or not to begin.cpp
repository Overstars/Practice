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
#define PI 3.14159265358979323846
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=200005;
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
	double p[1000]={1,0.5};
	for(int i=2;i<100;i++)
	{
		p[i]=(double)1/(i+1)+(double)(i-1)/(i+1)*p[i-2];
		cout<<"p["<<i<<"]="<<p[i]<<endl;
	}
	int k;//��������k�������һ������,�����Ƿ�������
	while(cin>>k)
	{//����ʽ:P(k)=1/(k+1)+(k-1)/(k+1)*P(k-2)
		if(k&1)
			cout<<0<<endl;
		else
			cout<<1<<endl;
	}
	return 0;
}
