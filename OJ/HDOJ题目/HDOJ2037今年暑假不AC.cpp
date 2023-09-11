//开会类型的题，贪心即可
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(struct program x,struct program y);
struct program
{
    int start;
    int endp;
} arr[105];
int main()
{
    int n;
    while(cin>>n&&n!=0){
        int i,cnt=0;
        for(i=0;i<n;i++)
            cin>>arr[i].start>>arr[i].endp;
        sort(arr,arr+n,cmp);
        int last=arr[0].endp;
        cnt=1;
        for(i=1;i<n;i++){
            if(arr[i].start>=last){
                last=arr[i].endp;
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
bool cmp(struct program x,struct program y)
{
    if(x.endp==y.endp)
        return x.start>y.start;
    return x.endp<y.endp;
}
