#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
char a[maxn],b[maxn];
int main()
{
	int n,cnt=0;
	unsigned long long c[4]={0};
	cin>>n>>a>>b;
	for(int i=0;i<n;i++)
		if(a[i]=='0')
		{
			if(b[i]=='0')
				c[0]++;//00
			else
				c[1]++;//01
		}
		else{
			if(b[i]=='0')
				c[2]++;//10
			else
				c[3]++;//11
		}
	cout<<c[0]*c[3]+c[0]*c[2]+c[1]*c[2]<<endl;
//	for(int i=0;i<4;i++)
//		printf("c[%d]=%d\n",i,c[i]);
	return 0;
}
