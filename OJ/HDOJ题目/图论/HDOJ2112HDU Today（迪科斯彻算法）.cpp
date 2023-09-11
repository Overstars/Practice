#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<map>
using namespace std;
void dijkstra(int beg,int n);
int citymap[200][200],dist[200],flag[200];//分别为地图，最短时间，站点最短路是否确定
//int pre[200];//当前最短路之前站点
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
void dijkstra(int beg,int n)//起点和车站个数
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
            if(dist[j]<temp&&!flag[j]){//寻找未确定点到源点最短路的点
                t=j;
                temp=dist[j];
            }
        }
        if(t==beg)
            return;
        else
            flag[t]=1;//t无法借助其他路径优化，即为最短
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
