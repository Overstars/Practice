#include<iostream>
#include<cstring>
using namespace std;
char s1[100005],s2[100005];
void delrear(char *s);
char * first(char *s);
int main()
{
    while(cin>>s1>>s2){
        char *p1=first(s1),*p2=first(s2);
        if(s1[0]!=s2[0]){
            cout<<"NO"<<endl;
            continue;
        }
        delrear(s1);
        delrear(s2);
        if(strcmp(p1,p2)==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
void delrear(char *s)
{
    char *p=s+strlen(s)-1;//指向最后一个数字
    while(*p=='0')
        *(p--)='\0';
    return;
}
char * first(char *s)
{
    char *p=s;
    while(*p=='0'||*p=='-')
        p++;
    return p;
}
