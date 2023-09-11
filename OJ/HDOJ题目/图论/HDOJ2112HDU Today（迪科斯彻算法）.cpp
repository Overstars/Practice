#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<map>
using namespace std;
void dijkstra(int beg,int n);
int citymap[200][200],dist[200],flag[200];//�ֱ�Ϊ��ͼ�����ʱ�䣬վ�����·�Ƿ�ȷ��
//int pre[200];//��ǰ���·֮ǰվ��
const int INF=0x3f3f3f3f;
int main()
{
    int n,time;
    string start,target,s1,s2;
    map<string,int>QAQ;
    while(scanf("%d",&n)==1&&n!=-1){
        QAQ.clear();
        memset(citymap,INF,sizeof(citymap));
//        memset(pre,-1,sizeof(int));
        memset(flag,0,sizeof(flag));
//        for(int i=1;i<=n;i++){
//            for(int j=1;j<=n;j++){
//                citymap[i][j]=INF;
//            }
//        }
        int cnt=0;
        cin>>start>>target;
        if(!QAQ[start])
            QAQ[start]=++cnt;
        if(!QAQ[target])
            QAQ[target]=++cnt;
        for(int i=0;i<n;i++){
            cin>>s1>>s2>>time;
            if(!QAQ[s1])
                QAQ[s1]=++cnt;
            if(!QAQ[s2])
                QAQ[s2]=++cnt;
            if(time<citymap[QAQ[s1]][QAQ[s2]]){
                citymap[QAQ[s1]][QAQ[s2]]=time;
                citymap[QAQ[s2]][QAQ[s1]]=time;
            }
        }

        if(start==target){
            cout<<"0"<<endl;
        }
        else
            dijkstra(QAQ[start],cnt);
//        {
//            printf("\n******\n");
//            for(int i=1;i<=cnt;i++){
//                for(int j=1;j<=cnt;j++){
////                    cout<<citymap[i][j]<<' ';
//                    printf("%10d ",citymap[i][j]);
//                }
//                cout<<endl;
//            }
//            cout<<endl;
//            printf("dist:\n");
//            for(int i=1;i<=cnt;i++)
//                printf("%d ",dist[i]);
//            printf("\nflag:\n");
//            for(int i=1;i<=cnt;i++)
//                printf("%d ",flag[i]);
//            printf("\n******\n");
//        }
        if(dist[QAQ[target]]==INF&&start!=target)
            cout<<"-1"<<endl;
        else if(start!=target)
            cout<<dist[QAQ[target]]<<endl;
    }
    return 0;
}
void dijkstra(int beg,int n)//���ͳ�վ����
{
    for(int i=1;i<=n;i++){
        dist[i]=citymap[beg][i];
//        flag[i]=0;
//        if(citymap[beg][i]==INF)
//            pre[i]=-1;
//        else
//            pre[i]=beg;
    }
    dist[1]=0;
    flag[beg]=1;
//    pre[beg]=-1;
    for(int i=1;i<=n;i++){
        int temp=INF,t=beg;
        for(int j=1;j<=n;j++){
            if(dist[j]<temp&&!flag[j]){//Ѱ��δȷ���㵽Դ�����·�ĵ�
                t=j;
                temp=dist[j];
            }
        }
        if(t==beg)
            return;
        else
            flag[t]=1;//t�޷���������·���Ż�����Ϊ���
//        {
//            printf("\n******\n");
//            for(int i=1;i<=n;i++){
//                for(int j=1;j<=n;j++){
////                    cout<<citymap[i][j]<<' ';
//                    printf("%10d ",citymap[i][j]);
//                }
//                cout<<endl;
//            }
//            cout<<endl;
//            printf("dist:\n");
//            for(int i=1;i<=n;i++)
//                printf("%d ",dist[i]);
//            printf("\nflag:\n");
//            for(int i=1;i<=n;i++)
//                printf("%d ",flag[i]);
//            printf("\n******\n");
//        }
        for(int j=1;j<=n;j++){
            if(citymap[t][j]<INF&&!flag[j]&&(dist[t]+citymap[t][j])<dist[j]){
                dist[j]=dist[t]+citymap[t][j];
//                pre[j]=t;
            }
        }
    }
}
