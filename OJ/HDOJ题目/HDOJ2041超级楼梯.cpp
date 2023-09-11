#include<iostream>
using namespace std;
long long fun(long long x);
long long arr[45]={0},a[45]={0};
int main()
{
    int t;
    cin>>t;
    while(t--){
        long long m;
        cin>>m;
        cout<<fun(m-1)<<endl;
    }
    return 0;
}
long long fun(long long x)
{
    if(a[x]==1)
        return arr[x];
    else if(x==0||x==1){
        a[x]=1;
        arr[x]=1;
        return arr[x];
    }
    else{
        arr[x]=fun(x-1)+fun(x-2);
        a[x]=1;
        return arr[x];
    }
}
