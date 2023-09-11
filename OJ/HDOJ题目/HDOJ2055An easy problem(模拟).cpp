#include<iostream>
#include<cctype>
using namespace std;
int main()
{
    char ch;
    int t,temp,ans;
    cin>>t;
    while(t--){
        cin>>ch>>temp;
        if(ch>='A'&&ch<='Z'){
            ans=ch-'A'+1;
        }
        else
            ans=-(ch-'a'+1);
        ans+=temp;
        cout<<ans<<endl;
    }
    return 0;
}
