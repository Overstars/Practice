#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int n,tian[1005],king[1005],cnt;
	while(cin>>n&&n){
		int i;
		cnt=0;
		for(i=0;i<n;i++)
			cin>>tian[i];
		for(i=0;i<n;i++)
			cin>>king[i];
		sort(tian,tian+n);
		sort(king,king+n);
		int *pts=tian,*pte=tian+n-1,*pks=king,*pke=king+n-1;
		while(pks<=pke||pts<=pte){
			if(*pte>*pke){
				cnt++;
				pte--;
				pke--;
			}
			else if(*pte<*pke){//��������С����,������������
				cnt--;
				pts++;
				pke--;
			}
			else{
				if(*pts>*pks){//����������Ŀ�
					cnt++;
					pts++;
					pks++;
				}
				else if(*pts<*pks){//��������,�����������
					cnt--;
					pts++;
					pke--;
				}
				else{//������ٶ���ͬ,�������ٶ���ͬ
					if(*pts<*pke){
						cnt--;
						pts++;
						pke--;
					}
					else{//���������ͬ
						break;
					}
				}
			}
		}
		cout<<cnt*200<<endl;
	}
	return 0;
}
//̰��,�����������
//�������ɵĿ�������Ŀ���죬���Ӯ��
//��������������������ɳ�������������
//������ٶ���ͬ���Ƚϵ�ǰ˫����������
//����������������������죬���ʤ
//������������������������
//�ٶ���ͬ,����������������
