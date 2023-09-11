#include<cstdio>
#include<iostream>
#include <iomanip>
using namespace std;
struct coord
{
    int x;
    int y;
} arr[105];
int main()
{
    int n;
    while(cin>>n&&n>0){
        int i;
        for(i=0;i<n;i++){
            cin>>arr[i].x>>arr[i].y;
        }
        double area=0;
        for(i=1;i<n;i++){
            area+=(double)(arr[i-1].x-arr[i].x)*(arr[i].y+arr[i-1].y)/2;
//            cout<<"area="<<area<<endl;
        }
        area+=(double)(arr[n-1].x-arr[0].x)*(arr[n-1].y+arr[0].y)/2;
//        cout.precision(1);
//        cout<<area<<endl;
//        cout <<setiosflags(ios::showpoint)<<setprecision(1) << area << endl;
        printf("%.1lf\n",area);
    }
    return 0;
}
