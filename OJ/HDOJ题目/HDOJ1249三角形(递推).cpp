#include<iostream>
using namespace std;
long long F[10005]={1,2,8};
int main()
{
	int i,t,n;
	for(i=2;i<10001;i++)
		F[i]=F[i-1]+6*(i-1);
	cin>>t;
	while(t--){
		cin>>n;
		cout<<F[n]<<endl;
	}
	return 0;
}
//�����n��������ʱ,��������һ�߶���֮ǰn-1��������ĳ�����ཻ,�γ�2(n-1)������
//���·ָ��2n-3������,��Ϊ������,���ߵļн�Ҳ�����²���,��������6n-6
