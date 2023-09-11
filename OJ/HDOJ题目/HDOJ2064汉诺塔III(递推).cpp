#include<iostream>
using namespace std;
int main(void)
{
	long long st[40]={0,2,8},i,n;
	for(i=3;i<37;i++){
		st[i]=3*st[i-1]+2;
	}
	while(cin>>n)
		cout<<st[n]<<endl;
	return 0;
}
//woc,这题我居然独立做出来了
//一共n层，先将上面n-1层移到㈢柱,再将第n层移至㈡柱
//再将㈢柱的n-1层移到㈠柱，再将㈡柱的第n层移至㈢柱,㈠柱的n-1层也移至㈢柱
//递推公式st[i]=3*st[i-1]+2;
//好吧，确实不难(っ °Д °;)っ
