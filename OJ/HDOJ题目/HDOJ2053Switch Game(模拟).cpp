#include<iostream>
using namespace std;
int fun(int a);
int main()
{
    int n,i;
    while(cin>>n){
        int ans=0;
        for(i=1;i<=n;i++)
            if(n%i==0)
               ans=fun(ans);
        cout<<ans<<endl;
    }
    return 0;
}
int fun(int a)
{
    if(a==1)
        return 0;
    else
        return 1;
}
