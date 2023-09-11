#include<iostream>
#include<cstdio>
#include<algorithm>
#include <cmath>
using namespace std;
double arr[1005];
typedef long long LL;
double round(double number, unsigned int bits) {
    double integerPart = floor(number);
    number -= integerPart;
    for (unsigned int i = 0; i < bits; ++i)
        number *= 10;
    number = floor(number + 0.5);
    for (unsigned int i = 0; i < bits; ++i)
        number /= 10;
    return integerPart + number;
}
int main()
{
	int n,i;
	double record;
	char str[200],ch;
	while(cin>>n){
		record=0;
		for(i=0;i<n;i++){
			while((ch=getchar())!='.');
			scanf("%s",str);
			if(str[2]>='5')
				record+=0.001*('9'-str[2]+1);
			else
				record-=0.001*(str[2]-'0');
		}
		printf("%.3lf\n",record);
	}
	return 0;
}
