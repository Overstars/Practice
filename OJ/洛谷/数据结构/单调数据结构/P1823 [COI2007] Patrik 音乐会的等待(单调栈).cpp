//#pragma G++ optimize("O2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=500005;
ll stk[maxn]={LLONG_MAX},ans;
int n,Ind=0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("P1823.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		ll tem;
		cin>>tem;
//		while(Ind>0&&stk[Ind]<tem)//维护一个单调递减的栈
//		{
//			Ind--;//弹栈
//            ans++;//tem和弹出的元素能观察到(栈是单调递减的)
//		}

//		int diff=0;
//		while(Ind>0&&stk[Ind]==tem)//计算等高,可以互相看到
//		{
//			Ind--;
//			diff++;//弹栈后须复原,因为会影响到后续
//			ans++;
//		}
//		if(Ind)
//			ans++;
//		Ind+=diff;//复原
//		cout<<i<<":diff="<<diff<<endl;

//		printf("stk:");
//		for(int j=1;j<=Ind;j++)
//		{
//			printf("%d ",stk[j]);
//		}
//		printf("\n");
		int l=1,r=Ind,mid,rec=Ind+1;//注意初始化rec
		while(l<=r)
		{
			mid=(l+r)>>1;//二分元素下标
			if(stk[mid]<=tem)
			{
				rec=mid;
				r=mid-1;
			}
			else
				l=mid+1;
		}

		if(rec>1)//rec为小于等于tem的最左下标
			ans+=Ind-rec+2;//和栈顶元素可以相互看见
		else
		{
			ans+=Ind;//看见前面所有人
		}

//		cout<<i<<":ans="<<ans<<",rec="<<rec<<",Ind="<<Ind<<endl;

		while(Ind>0&&stk[Ind]<tem)
			Ind--;
		stk[++Ind]=tem;
	}
	cout<<ans<<endl;
	return 0;
}
