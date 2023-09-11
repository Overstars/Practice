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
			else if(*pte<*pke){//田忌最快马小于王,用最慢马来打
				cnt--;
				pts++;
				pke--;
			}
			else{
				if(*pts>*pks){//最慢马比王的快
					cnt++;
					pts++;
					pks++;
				}
				else if(*pts<*pks){//比王的慢,用来打最快马
					cnt--;
					pts++;
					pke--;
				}
				else{//最快马速度相同,最慢马速度相同
					if(*pts<*pke){
						cnt--;
						pts++;
						pke--;
					}
					else{//否则就是相同
						break;
					}
				}
			}
		}
		cout<<cnt*200<<endl;
	}
	return 0;
}
//贪心,用两个数组存
//①如果田忌的快马比王的快马快，这局赢，
//②如果比王的马慢，则派出最慢的马来比
//③如果速度相同，比较当前双方最慢的马
//如果最慢的马比王的最慢马快，这局胜
//如果比王慢，消耗王的最快马
//速度相同,拿来和王的最快马比
