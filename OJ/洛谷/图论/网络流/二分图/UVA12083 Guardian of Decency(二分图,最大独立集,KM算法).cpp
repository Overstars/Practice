//#pragma G++ optimize("O2")
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<climits>
#include<cmath>
#include<iomanip>//�������,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<map>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int maxn=1005;
int w[maxn][maxn];//����ͼ���Ȩֵ
int lx[maxn],ly[maxn];
int linker[maxn];//Bͼƥ�䵽��Aͼ�ڵ�
int slack[maxn];
bool visy[maxn];//��¼ÿһ��Bͼƥ���
int pre[maxn];
void bfs(int k,int n)
{
    int x,y=0,yy=0,delta;
    memset(pre,0,sizeof(pre));
    for(int i=1;i<=n;i++)
		slack[i]=INF;
    linker[y]=k;
    while(1)
	{
        x=linker[y];
        delta=INF;
        visy[y]=true;
        for(int i=1;i<=n;i++)
		{
            if(!visy[i])
            {
                if(slack[i]>lx[x]+ly[i]-w[x][i])
                {
                    slack[i]=lx[x]+ly[i]-w[x][i];
                    pre[i]=y;
                }
                if(slack[i]<delta)
					delta=slack[i],yy=i;
            }
        }
        for(int i=0;i<=n;i++)
        {
            if( visy[i] )
				lx[linker[i]]-=delta,ly[i]+=delta;
            else
				slack[i]-=delta;
        }
        y=yy;
        if(linker[y]==-1)
			break;
    }
    while(y)
		linker[y]=linker[pre[y]],y=pre[y];
}
int KM(int n)
{
    memset(lx,0,sizeof(lx));
    memset(ly,0,sizeof(ly));
    memset(linker,-1,sizeof(linker));
    for(int i=1;i<=n;i++)
	{
        memset(visy,false,sizeof(visy));
        bfs(i,n);
    }
    int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(linker[i]!=-1)
			ans+=w[linker[i]][i];
	}
	return ans;
}
struct student
{
	int h;
	char sex;
	string music,sport;
	student()
	{
		h=0;
		sex='\0';
		music=sport="";
	}
	student(int h,char s,const string &mu,const string &sp):
		h(h),sex(s),music(mu),sport(sp){}
};
vector<student> Man,Woman;
inline bool judge(int x,int y)//��������������,Ϊ��
{
	if(abs(Man[x].h-Woman[y].h)>40)//��߲����40
		return 0;
	if(Man[x].sex==Woman[y].sex)//�Ա���ͬ
		return 0;
	if(Man[x].music.compare(Woman[y].music))//����ͬ
		return 0;
	if(!Man[x].sport.compare(Woman[y].sport))//��ͬ
		return 0;
	return 1;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
//	freopen("UVA12083.in","r",stdin);
//	freopen("out.ans","w",stdout);
	int t,n;
	int h;
	char sex;
	string mus,spo="213";
	cin>>t;
	while(t--)
	{
		cin>>n;
		int man=0,woman=0;
		Man.clear();
		Man.push_back(student(0,'M',spo,spo));
		Woman.clear();
		Woman.push_back(student(0,'F',spo,spo));
		for(int i=1;i<=n;i++)
		{
			cin>>h>>sex>>mus>>spo;
			if(sex=='M')
				Man.push_back(student(h,sex,mus,spo)),man++;
			else
				Woman.push_back(student(h,sex,mus,spo)),woman++;
		}
		memset(w,0,sizeof(w));
		for(int i=1;i<=man;i++)
			for(int j=1;j<=woman;j++)
			{
				if(judge(i,j))//���������ܵ�������,���ϵ�����ֻ��ȥһ��
				{
					w[i][j]=1;
//					w[j][i]=1;
				}
			}
		cout<<n-KM(n)<<endl;
	}
	return 0;
}
/*
��ʦҪ��ѧ���ǳ��Σ���������ֹѧ��������һЩ�����ʾ�����������Ŀ����Ժ�С
1.������40��������
2.ͬ��
3.ϲ�������ַ��ͬ
4.ϲ�����˶�����ͬ(��ֹ��ͬ���������е�����)
�μ��������е��κ����˱����������������һ����
����ɲμ����е����������

���룺
��һ�У���ʾ������������T
ÿ�����ݵĵ�һ����һ������n (n��500)
��������n�У�ÿ�����ĸ��ɿո����������
*����h����cmΪ��λ�����
*�ַ����� F������Ů �� M��������
*�ַ�����ϲ�������ַ��
*�ַ�����ϲ�����˶�

�����
��ÿ�����ݣ����

˼·����������=n-���ƥ����
��㣬�����������������ϵ�����ͬѧ��ͼ
*/
