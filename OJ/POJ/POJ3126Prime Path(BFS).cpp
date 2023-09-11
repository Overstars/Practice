#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
int vis[10000],ans;
struct node
{
	int num,step;
};
int prime( int x )
{
	if(x <= 1)
		return 0;
	if( x == 2 || x == 3 || x == 5 )
		return 1;
	if( x%2 == 0 || x%3 == 0 )	/*判断是否为2,3的倍数*/
		return 0;
	for(int i=6; i<=sqrt((float)x); i += 6 ){
		if( x % (i-1) == 0 || x % (i+1) == 0 )
			return 0;
	}
	return 1;
}
int change(int x,int n,int a)//将数字x第n位改为a
{
	int head=x,tail=0,edge=1;
	for(int i=0;i<n;i++){
		edge*=10;
	}
	tail=x%(edge/10);
	return (x/edge)*edge+a*edge/10+tail;
}
int bfs(int st,int ed)
{
	queue<node> QAQ;
	node now,nex;
	now.num=st,now.step=0;
	vis[now.num]=1;
	QAQ.push(now);
	while(!QAQ.empty()){
		now=QAQ.front();
		QAQ.pop();
		if(now.num==ed){
			ans=now.step;
			return 1;
		}
		for(int i=1;i<=4;i++)
			for(int j=0;j<10;j++){
				nex.num=change(now.num,i,j);
				if(!prime(nex.num))
					vis[nex.num]=1;
				if(vis[nex.num]||!prime(nex.num)||i==4&&j==0)
					continue;
				vis[nex.num]=1;
				nex.step=now.step+1;
				QAQ.push(nex);
			}
	}
	return 0;
}
int main()
{
	int t,start,tar;
	cin>>t;
	while(t--){
		cin>>start>>tar;
		memset(vis,0,sizeof(vis));
		if(bfs(start,tar))
			printf("%d\n",ans);
	}
	return 0;
}
