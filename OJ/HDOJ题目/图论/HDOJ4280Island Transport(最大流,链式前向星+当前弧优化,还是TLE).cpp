#pragma comment(linker,"/STACK:102400000,102400000")
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>//控制输出,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
//当前弧优化是用一个数组记录每次分层图后第i个点增广到哪一条边,
//每次增广一定是彻底增广,这样每次增广时都不走原来走过的边
//链式前向星+当前弧优化
const int maxn = 100015;//魔改上大的模板
const int maxm = 200030;
const int inf=0x3f3f3f3f;
struct Dinic
{
//private:
    struct Edge
    {
        int from,to,cap,flow,next;//容量,当前流量
        Edge(int u,int v, int c, int f):
            from(u), to(v), cap(c), flow(f) {}
    };
    int n,m,s,t;//结点数,边数(包括反向弧),源点编号和汇点编号
    vector<Edge> edges; //边表。edge[e]和edge[e^1]互为反向弧
    int depth[maxn]; //从起点到i的距离,源点到i经过的最少边数
    int cur[maxm]; //当前弧下标
    int head[maxm];//每一个点最后一条边的编号(当前弧优化)
public:
    inline void init(int n)
    {
        this->n = n;//初始化,n个节点
        this->m=0;
        edges.clear();
        memset(head,-1,sizeof(head));
    }
    inline void add(int from, int to, int cap,int flow=0)
    {
        edges[m].to=to;
        edges[m].cap=cap;
        edges[m].flow=flow;
        edges[m].next=head[from];
        head[from]=m++;
    }
    inline void AddEdge(int from, int to, int cap ,int flow=0)
    {
//        edges.emplace_back(Edge(from,to, cap, 0));//魔改蔡队模板
//        edges.emplace_back(Edge(to,from, cap, 0)); //反向弧,无向图就更改反向边容量为cap
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(to, from, 0, 0));
        m = (int)edges.size();//当前图上边数
//        G[from].push_back(m - 2);//该边正向边的编号:m-2
//        G[to].push_back(m - 1);//反向边的编号:m-1
        edges[m-2].next=head[from];
        head[from]=m-2;
        edges[m-1].next=head[to];
        head[to]=m-1;
    }
    bool BFS()//获得整张剩余图的深度
    {
        for(int i=1;i<=n;i++)
        {
            cur[i]=head[i];//建分层图后,把cur置为每一个点的第一条边
//            depth[i]=0;
        }
        memset(depth,0,sizeof(depth));
        queue<int> q;
        q.push(s);
        depth[s] = 1;//源点深度为1
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
//            cout<<"DEBUG: BFS.1 HAS BEEN RUN!"<<endl;
            for(int i=head[x];i!=-1;i=edges[i].next)
            {
//                printf("i=%d,next=%d\n",i,edges[i].next);
                Edge e=edges[i];
                if(depth[e.to]==0&&e.cap>e.flow)//没来过,且有剩余空间
                {
                    depth[e.to]=depth[x]+1;
                    q.push(e.to);//末端节点放入队列
                }
            }
//            cout<<"DEBUG: BFS.2 HAS BEEN RUN!"<<endl;
        }
        return depth[t]>0;//depth[t]为0时表示汇点无深度,无法再为t找到增广路
    }
    int DFS(int x, int a)//x为当前节点,a为源点到当前节点最小剩余容量
    {
        if(x == t || a == 0)
            return a;
//        cout<<"DEBUG: DFS HAS BEEN RUN!!!!!!!!!!"<<endl;
        int flow = 0;
        for(int& i=cur[x];i!=-1;i=edges[i].next)
        { //从上次考虑的弧,改变i的同时也能改变cur[x]的值,记录下榨取到哪里
//            Edge& e = edges[G[x][i]];//e为x->i边
            Edge& e=edges[i];
            if(depth[x]+1==depth[e.to]&&(e.cap-e.flow)>0)
            {//i的深度比x深1
                int f=DFS(e.to,min(a,e.cap-e.flow));
                if(f>0)//且为增广路(可带来增广流量)
                {
                    e.flow += f;//正向边流量增加f
                    edges[i^1].flow -= f;//反向边流量减少f
                    flow += f;//增广流量增加f
                    a -= f;//接下来的最小剩余容量减少f
                }
                if (a == 0)
                    break;
            }
        }
        if(!flow)
            depth[x]=-2;//炸点优化,不必要的点下次不用遍历
        return flow;
    }
    int Maxflow(int s, int t)
    {
        this->s = s, this->t = t;
        int flow = 0;
        while(BFS())
        {
            int inc;
            while(inc=DFS(s,inf))
                flow+=inc;
//            printf("flow=%d,inc=%d\n",flow,inc);
        }
        return flow;
    }
} di;
int read()//快读挂
{
    int x=0,f=1;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return x*f;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int ca,n,m;
//    cin>>ca;
    scanf("%d",&ca);
    while(ca--)
    {
//        cin>>n>>m;//点数,边数,源点,汇点
//        scanf("%d%d",&n,&m);
        n=read(),m=read();
        di.init(n);
        int s=0,t=0;
        int maxi=-inf,mini=inf;//maxi为最右端坐标,mini为最左端坐标
        for(int i=1;i<=n;i++)
        {
            int x,y;
//            cin>>x>>y;
//            scanf("%d%d",&x,&y);
            x=read(),y=read();
            if(x<mini)//最西边
            {
                s=i;
                mini=x;
            }
            if(x>maxi)//最东边
            {
                t=i;
                maxi=x;
            }
//            printf("maxi=%d,mini=%d,s=%d,t=%d\n",maxi,mini,s,t);
        }
        int u,v,w;
        for(int i=1;i<=m;i++)
        {
//            cin>>u>>v>>w;
//            scanf("%d%d%d",&u,&v,&w);
            u=read(),v=read(),w=read();
            di.add(u,v,w);
            di.add(v,u,w);
//            di.AddEdge(v,u,w);
        }
//        cout<<"ans=";
//        cout<<di.Maxflow(s,t)<<endl;
        printf("%d\n",di.Maxflow(s,t));
    }
    return 0;
}
