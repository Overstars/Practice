#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int vis[100005],n,k,ans;
struct node
{
	int n,step;
};
void bfs(int step,int n)
{
	node now,nex;
	now.n=n,now.step=step;
	queue<node> QAQ;
	QAQ.push(now);
	while(!QAQ.empty()){
		now=QAQ.front();
		QAQ.pop();
		if(now.n==k){
			ans=now.step;
			return;
		}
		if(now.n<0||now.n>100000||vis[now.n])
			continue;
		vis[now.n]=1;
		nex.step=now.step+1;
		nex.n=now.n-1;
		QAQ.push(nex);
		nex.n=2*now.n;
		QAQ.push(nex);
		nex.n=now.n+1;
		QAQ.push(nex);
	}
}
int main()
{
	cin>>n>>k;
	bfs(0,n);
	cout<<ans<<endl;
	return 0;
}
