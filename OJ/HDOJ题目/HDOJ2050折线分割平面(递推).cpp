//将当前加入折线看成两段，每段都与之前折线的两边有2*(n-1)个交点，每边产生2n-3个线段，1条射线，1个折角的一边
//一个射线或线段产生一个新区域，折角算一个新区域，两条共产生4n-3个新区域
#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int c,i,TAT[10005]={0,2,7};
    for(i=3;i<10003;i++)
        TAT[i]=TAT[i-1]+(i-1)*4+1;
    cin>>c;
    while(c--){
        int n;
        cin>>n;
        cout<<TAT[n]<<endl;
    }
//    for(i=4;i<10003;i++)
//        cout<<TAT[i]<<endl;
    return 0;
}
