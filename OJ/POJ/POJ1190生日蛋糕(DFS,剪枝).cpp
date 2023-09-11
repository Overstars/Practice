#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int mini,area;
int n,m,flag,minV[30],minA[30];
int OverMaxV(int m,int r,int h)//第m层,半径r,高度h
{
	int ret=0;
	for(int i=0;i<m;i++)//向上计算m层的最大体积
		ret+=(r-i)*(r-i)*(h-i);
	return ret;
}
void dfs(int v,int floor,int R,int H)
{//剩余体积,当前层数,当前的R,当前的H
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
			area=r*r;//最底层,计算上表面面积
		for(int h=H-1;h>=floor;h--){
			area+=2*r*h;//加上侧面积
			dfs(v-r*r*h,floor-1,r,h);
			area-=2*r*h;//还原
		}
	}
}
int main()
{
	for(int i=1;i<21;i++){//自顶向下,累积的最小体积
		minV[i]=minV[i-1]+i*i*i;//层数即为最小半径or高度
		minA[i]=minA[i-1]+2*i*i;
	}
	mini=99999999999;
	area=0;
	cin>>n>>m;//自底向上搜索
	int maxH=(n-minV[m-1])/(m*m)+1;
	int maxR=sqrt((n-minV[m-1])*1.0/m)+1;
	dfs(n,m,maxR,maxH);
	if(flag)
		cout<<mini<<endl;
	else
		cout<<0<<endl;
	return 0;
}
