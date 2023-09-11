#include<bits/stdc++.h>
using namespace std;
const int MAXN=100001;
struct node//链式前向星
{
    int v;
    int next;
}G[MAXN];
int head[MAXN];
int cnt;
struct stu
{
    int h;
    char sex;
    string musics;
    string sports;
    stu(){sports = musics = "12213124142";}

}stu[MAXN];
int num=0;
void add(int u,int v)//加边
{
    G[++cnt].v=v;
    G[cnt].next=head[u];
    head[u]=cnt;
}
int result[MAXN];
bool vis[MAXN];
int ans;
int find(int p)//最大匹配
{
    for(int i=head[p];i;i=G[i].next)
    {
        int to=G[i].v;;
        if(!vis[to])
        {
            vis[to]=true;
            if(!result[to])
            {
                result[p]=to;
                result[to]=p;
                return 1;
            }
            else if(find(result[to]))
            {
                result[p]=to;
                result[to]=p;
                return 1;
            }
        }
    }
    return 0;
}
bool music(int i,int j)
{
    int ans=stu[i].musics.compare(1,stu[i].musics.length(),stu[j].musics,1,stu[j].musics.length());
    if(ans==0) return true;
    else return false;
}
bool sports(int i,int j)
{
    int ans=stu[i].sports.compare(1,stu[i].sports.length(),stu[j].sports,1,stu[j].sports.length());
    if(ans==0) return false;
    else return true;
}
bool judge(int x,int y)
{
    if(abs(stu[x].h-stu[y].h)>40)//身高差大于40
		return 0;
    if(stu[x].sex==stu[y].sex)//性别相同
		return 0;
	if(stu[x].musics.compare(stu[y].musics))//不相同
		return 0;
	if(!stu[x].sports.compare(stu[y].sports))//相同
		return 0;
    return 1;
}
int main()
{
    freopen("UVA12083.in","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        memset(G,0,sizeof(G));
        memset(head,0,sizeof(head));
        cnt=0;
        memset(result,0,sizeof(result));
        num=0;
        ans=0;
        cin>>num;
        for(int i=1;i<=num;i++)
        {
            cin>>stu[i].h;
            cin>>stu[i].sex;
            cin>>stu[i].musics;
            cin>>stu[i].sports;
            for(int j=1;j<i;j++)
            {
//                if((-40<=stu[i].h-stu[j].h && stu[i].h-stu[j].h<=40) && stu[i].sex!=stu[j].sex && sports(i,j)&&music(i,j))
                if(judge(i,j))
                {
                    add(i,j);
//                    add(j,i);
                }
            }
        }
        for(int i=1;i<=num;i++)
        {
            if(!result[i])
            {
                memset(vis,0,sizeof(vis));
                ans+=find(i);
            }
        }
        cout<<num-ans<<endl;
        for(int i=1;i<=num;i++)//不要忘记清零
        {
            stu[i].sex=' ';
            stu[i].h=0;
            stu[i].musics.clear();
            stu[i].sports.clear();
        }
    }
    return 0;
}
