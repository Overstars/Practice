#include<iostream>
#include<cstdio>
using namespace std;//��2k����,������Сm,ʹ�ú�k��������
int fun(int k)
{
	int m,n,pos;//kill��¼��������
	for(m=k+1;;m++){//��С����ö�ٳ���,����m���˱�ɱ
		n=2*k,pos=0;
		while(n>k){
			pos=(pos+m-1)%n;//��ɱ���˱��=(��һ����ɱ����λ��+m-1)%(ʣ������)
			if(pos<k)//��ɱ����(���˱��0~k-1)
				break;
			n--;//ɱ��,֮����˱��ǰ��
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
