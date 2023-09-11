#include<iostream>
using namespace std;
long long F[10005]={1,2,8};
int main()
{
	int i,t,n;
	for(i=2;i<10001;i++)
		F[i]=F[i-1]+6*(i-1);
	cin>>t;
	while(t--){
		cin>>n;
		cout<<F[n]<<endl;
	}
	return 0;
}
//加入第n个三角形时,其中任意一边都与之前n-1个三角形某两边相交,形成2(n-1)个交点
//即新分割出2n-3个部分,因为有三边,两边的夹角也产生新部分,所以新增6n-6
