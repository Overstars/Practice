#include<iostream>
using namespace std;
typedef long long ll;
ll F1[30]={0,1,4},F2[30]={0,2,4};//F1为将上n-1移到相邻柱子上所需步数(下标代表移动数量),F2为整个移到最右边所需步数
//通项公式：①F2[n]=2F1[n-1]+2,②F1[n]=3F1[n-1]+1
int main()
{
	int i,n,t;
	for(i=3;i<=21;i++)
		F1[i]=3*F1[i-1]+1;
	for(i=3;i<=21;i++)
		F2[i]=2*F1[i-1]+2;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<F2[n]<<endl;
	}
	return 0;
}
