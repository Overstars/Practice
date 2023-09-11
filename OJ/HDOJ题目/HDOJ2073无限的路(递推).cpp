
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int count(int n);
double cal(int n);
int main(){
    int n,x1,y1,x2,y2;
    cin>>n;
    while(n--){
        cin>>x1>>y1>>x2>>y2;double t1,t2;
        if(x1+y1>=1)
        t1=count(x1+y1-1);
        else
           t1=0;
        if(x2+y2>=1)
        t2=count(x2+y2-1);
        else
          t2=0;
        t1=sqrt(2.0)*(t1+x1)+cal(x1+y1);
        t2=sqrt(2.0)*(t2+x2)+cal(y2+x2);
        cout<<fixed<<setprecision(3)<<fabs(t1-t2)<<endl;
    }return 0;
}
int count(int n){
    int s=0;
    int t=n;
    while(n--)
        s+=n;
    return s+t;
}
double cal(int n){
    double s=0;
    for(double i=n;i>0;i--){
        s+=sqrt(i*i+(i-1)*(i-1));
    }return s;
}
