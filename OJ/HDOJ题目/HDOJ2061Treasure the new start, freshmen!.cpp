#include<iostream>
#include<iomanip>
#include <string>
using namespace std;
int main()
{
	int n,k,flag=0,in=0;
	double c,s;
	string str;
	cin>>n;
	while(n--){
		if(in)
			cout<<endl;
		in=1;
		flag=0;
		double sum1=0,sum2=0;
		cin>>k;
		for(int i=0;i<k;i++){
			cin>>str>>c>>s;
			if(s<60){
				flag=1;
			}
			sum1+=c*s;
			sum2+=c;
		}
		if(flag)
			cout<<"Sorry!"<<endl;
		else
			cout<<setiosflags(ios::fixed)<<setprecision(2)<<sum1/sum2<<endl;
	}
	return 0;
}
