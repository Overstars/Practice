#include<iostream>
using namespace std;
int main()
{
    long long arr[55]={0,1,2,3},i;
    for(i=4;i<55;i++)
        arr[i]=arr[i-1]+arr[i-2];
    int n;
    while(cin>>n)
        cout<<arr[n]<<endl;
    return 0;
}
