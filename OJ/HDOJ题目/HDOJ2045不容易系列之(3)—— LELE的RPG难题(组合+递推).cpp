//有些类似圆排列，但是有确定起点
//考虑当前格子时，一定不会与1相同。但是考虑下一个格子时，要额外考虑上一个格子与第一个相同的情况
#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    long long arr[55]={0,3,6,6};
    int i;
    for(i=4;i<52;i++){//涂第n个格子时，n-1有两种情况：与1相同或不同。
            //不同的话，只能填剩下的一种。这部分=F(n-1)。
            //1与n-1相同的话，可以填与1不同的两种，对应情况F(n-2)*2
        arr[i]=arr[i-1]+arr[i-2]*2;
    }
    int n;
    while(cin>>n)
        cout<<arr[n]<<endl;
    return 0;
}
