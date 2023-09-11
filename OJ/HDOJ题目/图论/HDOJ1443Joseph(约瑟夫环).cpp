#include<iostream>
#include<cstdio>
using namespace std;//有2k个人,给出最小m,使得后k个人先死
int fun(int k)
{
	int m,n,pos;//kill记录死的人数
	for(m=k+1;;m++){//从小到大枚举尝试,数到m的人被杀
		n=2*k,pos=0;
		while(n>k){
			pos=(pos+m-1)%n;//被杀的人编号=(上一个被杀的人位置+m-1)%(剩下人数)
			if(pos<k)//错杀好人(好人编号0~k-1)
				break;
			n--;//杀掉,之后的人编号前移
		}
	if(pos>=k&&n==k)
		break;
	}
	return m;
}
int main()
{
	int ans[14]={0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881},k;
	while(cin>>k&&k)
		cout<<ans[k]<<endl;
	return 0;
}
