#include <bits/stdc++.h>
using namespace std;

int f(string state)//计算曼哈顿距离作为辅助函数
{
    int res=0;
    for(int i=0;i<9;i++)
    {
        if(state[i]!='x')
        {
            int x=i/3,y=i%3;
            int ix=(state[i]-'1')/3,iy=(state[i]-'1')%3;
            res+=abs(x-ix)+abs(y-iy);
        }
    }
    return res;
}

string A_star(string start)
{
    string end="12345678x";
    unordered_map<string,int>dis;//记录每个状态的最小移动步数.
    unordered_map<string,pair<string,char>>pre;//用于记录答案
    char op[]="uldr";
    int dx[4]={-1,0,1,0};int dy[4]={0,-1,0,1};//四个方向 上左下右
    priority_queue<pair<int,string>,vector<pair<int,string>>,greater<>>q;//优先曼哈顿距离,然后存图
    q.push({f(start),start});
    dis[start]=0;
    while(q.size())
    {
        auto t=q.top();
        q.pop();
        int distance=t.first;
        string state=t.second;
        int x,y;
        if(state==end) break;
        for(int i=0;i<9;i++)
        {
             if(state[i]=='x') {x=i/3,y=i%3;break;}
        }//寻找x所在位子
        string source=state;
        for(int i=0;i<4;i++)
        {
            int a,b;
            a=x+dx[i],b=y+dy[i];
            if(a>=0&&a<3&&b>=0&&b<3)//判断是否越界
            {//假如没越界
                swap(state[3*x+y],state[3*a+b]);
                if(!dis.count(state)||dis[state]>distance+1)
                {
                    dis[state]=distance+1;
                    pre[state]={source,op[i]};
                    q.push({dis[state]+f(state),state});
                }
                swap(state[3*x+y],state[3*a+b]);
            }
        }
    }
    //记录答案
    string ans;
    while(end!=start)
    {
        ans=pre[end].second+ans;//接在前面
        end=pre[end].first;
    }
    return ans;
}

int main()
{
    string s,c,b;
    while(cin>>c)
    {
        s+=c;
        if(c!="x") b+=c;
    }
    int len=s.size();int cnt=0;
    for(int i=0;i<len;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            if(b[i]>b[j]) cnt++;
        }
    }
    if(cnt&1) puts("unsolvable");
    else
    {
        cout<<A_star(s)<<endl;
    }
    return 0;
}
