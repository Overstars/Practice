#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int ma[2100]={14,13,12,11,9,8,14,13,11,10,9,8,13,12,11,10,8,14,13,12,10,9,8,14,12,11,10,9,14,13,12,11,9,8,14,13,11,10,9,8,13,12,11,10,8,14,13,12,10,9,8,14,12,11,10,9,14,13,12,11,9,8,14,13,11,10,9,8,13,12,11,10,8,14,13,12,10,9,8,14,12,11,10,9,14,13,12,11,9,8,14,13,11,10,9,8,13,12,11,10,9};
int fa[2100]={18,17,16,15,20,19,18,17,15,21,20,19,17,16,15,21,19,18,17,16,21,20,19,18,16,15,21,20,18,17,16,15,20,19,18,17,15,21,20,19,17,16,15,21,19,18,17,16,21,20,19,18,16,15,21,20,18,17,16,15,20,19,18,17,15,21,20,19,17,16,15,21,19,18,17,16,21,20,19,18,16,15,21,20,18,17,16,15,20,19,18,17,15,21,20,19,17,16,15,21,20};
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,y,m,d;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&y,&m,&d);//年月日
		int d1=ma[y-2000],d2=fa[y-2000];
		if(m<5||(m==5&&d<d1))//今年母亲节
		{
			if(d1==1||d1==21||d1==31)
				printf("Mother's Day: May %dst, %d\n",d1,y);
			else if(d1==2||d1==22)
				printf("Mother's Day: May %dnd, %d\n",d1,y);
			else if(d1==3||d1==23)
				printf("Mother's Day: May %drd, %d\n",d1,y);
			else
				printf("Mother's Day: May %dth, %d\n",d1,y);
		}
		else if((m==5&&d>=d1)||(m==6&&d<d2))
		{
			if(d2==1||d2==21||d2==31)
				printf("Father's Day: June %dst, %d\n",d2,y);
			else if(d2==2||d2==22)
				printf("Father's Day: June %dnd, %d\n",d2,y);
			else if(d2==3||d2==23)
				printf("Father's Day: June %drd, %d\n",d2,y);
			else
				printf("Father's Day: June %dth, %d\n",d2,y);
		}
		else{//下一年母亲节
			y++;
			d1=ma[y-2000];
			if(d1==1||d1==21||d1==31)
				printf("Mother's Day: May %dst, %d\n",d1,y);
			else if(d1==2||d1==22)
				printf("Mother's Day: May %dnd, %d\n",d1,y);
			else if(d1==3||d1==23)
				printf("Mother's Day: May %drd, %d\n",d1,y);
			else
				printf("Mother's Day: May %dth, %d\n",d1,y);
		}
	}
	return 0;
}


