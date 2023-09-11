#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int mini,area;
int n,m,flag,minV[30],minA[30];
int OverMaxV(int m,int r,int h)//��m��,�뾶r,�߶�h
{
	int ret=0;
	for(int i=0;i<m;i++)//���ϼ���m���������
		ret+=(r-i)*(r-i)*(h-i);
	return ret;
}
void dfs(int v,int floor,int R,int H)
{//ʣ�����,��ǰ����,��ǰ��R,��ǰ��H
	if(floor==0){
		if(v==0){
			flag=1;
			mini=min(mini,area);
		}
		return;
	}
	if(v<0||v<minV[floor]||R<floor||H<floor)
		return;
	if(OverMaxV(floor,R,H)<v)
		return;
	if(area+minA[floor]>=mini)
		return;
	for(int r=R-1;r>=floor;r--){
		if(floor==m)
			area=r*r;//��ײ�,�����ϱ������
		for(int h=H-1;h>=floor;h--){
			area+=2*r*h;//���ϲ����
			dfs(v-r*r*h,floor-1,r,h);
			area-=2*r*h;//��ԭ
		}
	}
}
int main()
{
	for(int i=1;i<21;i++){//�Զ�����,�ۻ�����С���
		minV[i]=minV[i-1]+i*i*i;//������Ϊ��С�뾶or�߶�
		minA[i]=minA[i-1]+2*i*i;
	}
	mini=99999999999;
	area=0;
	cin>>n>>m;//�Ե���������
	int maxH=(n-minV[m-1])/(m*m)+1;
	int maxR=sqrt((n-minV[m-1])*1.0/m)+1;
	dfs(n,m,maxR,maxH);
	if(flag)
		cout<<mini<<endl;
	else
		cout<<0<<endl;
	return 0;
}
