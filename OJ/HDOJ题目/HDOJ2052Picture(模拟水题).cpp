#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int n,m,i,j;
    while(cin>>n>>m){
        cout<<'+';
        for(i=0;i<n;i++)
            cout<<'-';
        cout<<'+'<<endl;
        for(i=0;i<m;i++){
            cout<<'|';
            for(j=0;j<n;j++)
                cout<<' ';
            cout<<'|'<<endl;
        }
        cout<<'+';
        for(i=0;i<n;i++)
            cout<<'-';
        cout<<'+'<<'\n'<<endl;
    }
    return 0;
}
