//����ǰ�������߿������Σ�ÿ�ζ���֮ǰ���ߵ�������2*(n-1)�����㣬ÿ�߲���2n-3���߶Σ�1�����ߣ�1���۽ǵ�һ��
//һ�����߻��߶β���һ���������۽���һ������������������4n-3��������
#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int c,i,TAT[10005]={0,2,7};
    for(i=3;i<10003;i++)
        TAT[i]=TAT[i-1]+(i-1)*4+1;
    cin>>c;
    while(c--){
        int n;
        cin>>n;
        cout<<TAT[n]<<endl;
    }
//    for(i=4;i<10003;i++)
//        cout<<TAT[i]<<endl;
    return 0;
}
