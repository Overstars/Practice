#include<iostream>
using namespace std;
bool jud[1003];
int main()
{
	int sum,i,j,n,t;
	for(i=1;i<=994009;i++){//994009是997的平方
		sum=0;
		for(j=1;j<i;j++){
			if(i%j==0)
				sum+=j;
			if(sum>1000)
				break;
		}
		if(sum<=1000&&sum>0)
			jud[sum]=1;
	}
	cin>>t;
	while(t--){
		cin>>n;
		if(jud[i])
			cout<<"no"<<endl;
		else
			cout<<"yes"<<endl;
	}
	return 0;
}
