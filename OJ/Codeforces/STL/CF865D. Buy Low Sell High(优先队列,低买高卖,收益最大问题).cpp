#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	scanf("%d",&n);
	ll ans=0,tem;
	priority_queue<ll,vector<ll> ,less<ll> > QAQ;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&tem);
		QAQ.push(-tem);//�ȼ���ÿ�춼��
		QAQ.push(-tem);
		ans+=tem+QAQ.top();//ȡ������˵�����۸�
		QAQ.pop();//�������βű�ʾ����
	}
	cout<<ans<<endl;
	return 0;
}
