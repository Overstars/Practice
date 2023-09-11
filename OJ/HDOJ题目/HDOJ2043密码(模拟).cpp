#include<cstdio>
#include<iostream>
#include<cctype>
#include<cstring>
using namespace std;
char str[100];
int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>str;
        int a[4]={0,0,0,0};
        if(strlen(str)<8||strlen(str)>16){
            cout<<"NO"<<endl;
            continue;
        }
        for(int i=0;i<strlen(str);i++){
            if(isupper(str[i])!=0)
                a[0]=1;
            else if(islower(str[i])!=0)
                a[1]=1;
            else if(isdigit(str[i])!=0)
                a[2]=1;
            else if(str[i]=='~'||str[i]=='!'||str[i]=='@'||str[i]=='#'||str[i]=='$'||str[i]=='%'||str[i]=='^')
                a[3]=1;
        }
        if(a[0]+a[1]+a[2]+a[3]>=3)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
