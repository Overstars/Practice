//HDOJ-2047��ţ��EOFţ�⴮
//���ƣ������ַ�����nλ���n-1λ�ǲ���O�й�
//����nΪO��n-1һ����ΪO��n-2���⣬n-1ΪE��F���ⲿ��ΪF(n-2)*2
//����n��ΪO��n-1�������ȡ��nΪE��F��F(n-1)*2
#include<iostream>
using namespace std;
int main()
{
    long long arr[45]={0,3,8},i;
    for(i=3;i<45;i++)
        arr[i]=2*arr[i-1]+2*arr[i-2];
    int n;
    while(cin>>n)
        cout<<arr[n]<<endl;
    return 0;
}
