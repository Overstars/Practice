//HDOJ-2047阿牛的EOF牛肉串
//递推，三个字符，第n位与第n-1位是不是O有关
//假如n为O，n-1一定不为O，n-2任意，n-1为E或F，这部分为F(n-2)*2
//假如n不为O，n-1可以随便取，n为E或F，F(n-1)*2
#include<iostream>
using namespace std;
int main()
{
    long long arr[45]={0,3,8},i;
    for(i=3;i<45;i++)
        arr[i]=2*arr[i-1]+2*arr[i-2];
    int n;
    while(cin>>n)
        cout<<arr[n]<<endl;
    return 0;
}
