//这题是卡特兰数,数据太大不能用阶乘运算
//我推的错误通项公式F[n]=F[n-1]+C(2n-3,n-2)-F[n-3]……
#include<iostream>
using namespace std;
long long arr[40]={1,1,2,5};
int main()
{
	int i,j,n,cnt=0;
	for(i=4;i<36;i++){
		long long temp=0;
		for(j=0;j<i;j++)
			temp+=arr[j]*arr[i-j-1];
		arr[i]=temp;
	}
	while(cin>>n&&n!=-1)
		cout<<++cnt<<' '<<n<<' '<<2*arr[n]<<endl;
	return 0;
}
