#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>//�������,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
const int arraysize=305;
const int maxData=0x7fffffff;
int capacity[arraysize][arraysize]; //��¼�������������
int flow[arraysize];    //��Ǵ�Դ�㵽��ǰ�ڵ�ʵ�ʻ�ʣ������������
int pre[arraysize];     //���������·���ϵ�ǰ�ڵ��ǰ��,ͬʱ��Ǹýڵ��Ƿ��ڶ�����
int n,m;//����,����
queue<int> myqueue;
int BFS(int src,int des)
{
    while(!myqueue.empty())       //�������
        myqueue.pop();
    for(int i=1;i<n+1;++i)
        pre[i]=-1;
    pre[src]=0;
    flow[src]= maxData;//����ʣ��������Ϊinf
    myqueue.push(src);//��Դ�㿪ʼ����
    while(!myqueue.empty())
    {
        int index = myqueue.front();
        myqueue.pop();
        if(index == des)            //�ҵ�������·��
            break;//������
        for(int i=1;i<n+1;++i)//����n���ڵ�
        {//��s��������0�Ҳ��ڶ�����
            if(i!=src && capacity[index][i]>0 && pre[i]==-1)
            {
                 pre[i] = index; //��¼ǰ��
                 flow[i] = min(capacity[index][i],flow[index]);   //�ؼ����������ҵ�����
                 myqueue.push(i);
            }
        }
    }
    if(pre[des]==-1)      //����ͼ�в��ٴ�������·��
        return -1;
    else
        return flow[des];
}
int maxFlow(int src,int des)
{
    int increasement= 0;
    int sumflow = 0;
    while((increasement=BFS(src,des))!=-1)//��Ȼ��������·��
    {
         int k = des;          //����ǰ��Ѱ��·��
         while(k!=src)
         {
              int last = pre[k];//�ӻ�����...
              capacity[last][k] -= increasement; //�ı�����ߵ�����
              capacity[k][last] += increasement; //�ı䷴��ߵ�����
              k = last;
         }
         sumflow += increasement;//�ɹ�������·��
    }
    return sumflow;
}
int main()
{
    int ci;
    while(cin>>n>>m)//����,����,Դ��,���
    {
        memset(capacity,0,sizeof(capacity));
        memset(flow,0,sizeof(flow));
        for(int i=0;i<n;++i)
        {
            int u,v;
            cin>>u>>v>>ci;//�ߵ����˼�Ȩֵ
            if(u==v)               //��������յ���ͬ�����
               continue;
            capacity[u][v] +=ci;     //�˴�ע����ܳ��ֶ���ͬһ����յ�����
        }
        cout<<maxFlow(1,m)<<endl;
    }
    return 0;
}
