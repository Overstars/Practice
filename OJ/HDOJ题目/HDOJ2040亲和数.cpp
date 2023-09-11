#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        long long m,n,s1=0,s2=0,i;
        cin>>m>>n;
        for(i=1;i<m;i++){
            if(m%i==0){
                s1+=i;
            }
        }
        for(i=1;i<n;i++){
            if(n%i==0){
                s2+=i;
            }
        }
        if(m==s2&&n==s1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
