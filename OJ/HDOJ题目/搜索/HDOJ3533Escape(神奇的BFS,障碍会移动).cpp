#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct tower
{
	char ch;//�������,�ӵ���СA���ܴ����Ǳ�
	int t,v;
} tow[101][101];//�ӵ���A���ƶ�������ɢ�ģ�ֻ��ͬʱ������ͬһ�㣬A�Żᱻɱ��
int m,n,k,d,ans;//�Ǳ�����k,d���ڵ���
bool vis[1001][101][101];//��int��MLE�ɹ�
int nx[5]={1,0,-1,0,0},ny[5]={0,1,0,-1,0};
struct node
{
	int x,y,time;
};
int bfs(int x,int y,int time)
{
	node now;
	now.x=x,now.y=y,now.time=time;
	queue<node>QAQ;
	QAQ.push(now);
	vis[time][x][y]=1;
	while(!QAQ.empty()){
		now=QAQ.front();
		QAQ.pop();
//		printf("time:%d,x=%d,y=%d\n",now.time,now.x,now.y);
		if(now.time>d)
			break;
		if(now.x==m&&now.y==n){
			ans=now.time;
			return 1;
		}
		for(int i=0;i<5;i++){
			node nex;
			nex.x=now.x+nx[i];
			nex.y=now.y+ny[i];
			nex.time=now.time+1;
			if(nex.x<0||nex.x>m||nex.y<0||nex.y>n||vis[nex.time][nex.x][nex.y]||tow[nex.x][nex.y].t||nex.time>d)
				continue;
			int flag=1;//�Ƿ�ᱻ����
			if(!tow[nex.x][nex.y].t){//����֮��û����
					for(int j=nex.x-1;j>=0;j--)
						if(tow[j][nex.y].t)//�ҵ���һ����̨
							if(tow[j][nex.y].ch!='S')//�����¿���
								break;
							else{//���¿���
								int dist=nex.x-j;//����
								if(dist%tow[j][nex.y].v)
									break;//�ӵ���������ڸõ�
								int time2=dist/tow[j][nex.y].v;//��һ���ӵ��ɵ������ʱ��
								if(nex.time<time2)//��һ���ӵ���û�ɵ�
									break;//��ȫ
								if((nex.time-time2)%tow[j][nex.y].t==0){
									flag=0;
									break;
								}
							}

					if(flag==0)
						continue;//�����÷���ѭ��,�����¸�����
					for(int j=nex.x+1;j<=m;j++)
						if(tow[j][nex.y].t)//�ҵ���һ����̨
							if(tow[j][nex.y].ch!='N')//�����Ͽ���
								break;
							else{
								int dist=j-nex.x;//����
								if(dist%tow[j][nex.y].v)
									break;//�ӵ���������ڸõ�
								int time2=dist/tow[j][nex.y].v;//��һ���ӵ��ɵ������ʱ��
								if(nex.time<time2)
									break;//��ȫ
								if((nex.time-time2)%tow[j][nex.y].t==0){
									flag=0;
									break;
								}
							}

					if(flag==0)
						continue;
					for(int j=nex.y-1;j>=0;j--)
						if(tow[nex.x][j].t)//�ҵ���һ����̨
							if(tow[nex.x][j].ch!='E')//�����ҿ���
								break;
							else{//���ҿ���
								int dist=nex.y-j;//����
								if(dist%tow[nex.x][j].v)
									break;//�ӵ���������ڸõ�
								int time2=dist/tow[nex.x][j].v;//��һ���ӵ��ɵ������ʱ��
								if(nex.time<time2)
									break;//��ȫ
								if((nex.time-time2)%tow[nex.x][j].t==0){
									flag=0;
									break;
								}
							}

					if(flag==0)
						continue;
					for(int j=nex.y+1;j<=n;j++)
						if(tow[nex.x][j].t)//�ҵ���һ����̨
							if(tow[nex.x][j].ch!='W')//��������
								break;
							else{//������
								int dist=j-nex.y;//����
								if(dist%tow[nex.x][j].v)
									break;//�ӵ���������ڸõ�
								int time2=dist/tow[nex.x][j].v;//��һ���ӵ��ɵ������ʱ��
								if(nex.time<time2)
									break;//��ȫ
								if((nex.time-time2)%tow[nex.x][j].t==0){
									flag=0;
									break;
								}
							}

					vis[nex.time][nex.x][nex.y]=1;
					if(flag==0)
						continue;
					QAQ.push(nex);
			}
		}
	}
	return 0;
}
int main()//��0,0��m,n
{
	while(cin>>m>>n>>k>>d){
		char ch;
		int t,v,x,y;//����,����,�Ǳ�λ��
		memset(vis,0,sizeof(vis));
		memset(tow,0,sizeof(tow));
		for(int i=0;i<k;i++){
			scanf(" %c%d%d%d%d",&ch,&t,&v,&x,&y);//ע��x,y
			tow[x][y].ch=ch,tow[x][y].t=t,tow[x][y].v=v;//�ڵ�ͼ�ϱ������λ��
		}
		if(bfs(0,0,0))
			cout<<ans<<endl;
		else
			cout<<"Bad luck!"<<endl;
	}
	return 0;
}
