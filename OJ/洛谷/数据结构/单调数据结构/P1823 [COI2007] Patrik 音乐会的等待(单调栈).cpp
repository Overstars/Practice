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
//		while(Ind>0&&stk[Ind]<tem)//ά��һ�������ݼ���ջ
//		{
//			Ind--;//��ջ
//            ans++;//tem�͵�����Ԫ���ܹ۲쵽(ջ�ǵ����ݼ���)
//		}

//		int diff=0;
//		while(Ind>0&&stk[Ind]==tem)//����ȸ�,���Ի��࿴��
//		{
//			Ind--;
//			diff++;//��ջ���븴ԭ,��Ϊ��Ӱ�쵽����
//			ans++;
//		}
//		if(Ind)
//			ans++;
//		Ind+=diff;//��ԭ
//		cout<<i<<":diff="<<diff<<endl;

//		printf("stk:");
//		for(int j=1;j<=Ind;j++)
//		{
//			printf("%d ",stk[j]);
//		}
//		printf("\n");
		int l=1,r=Ind,mid,rec=Ind+1;//ע���ʼ��rec
		while(l<=r)
		{
			mid=(l+r)>>1;//����Ԫ���±�
			if(stk[mid]<=tem)
			{
				rec=mid;
				r=mid-1;
			}
			else
				l=mid+1;
		}

		if(rec>1)//recΪС�ڵ���tem�������±�
			ans+=Ind-rec+2;//��ջ��Ԫ�ؿ����໥����
		else
		{
			ans+=Ind;//����ǰ��������
		}

//		cout<<i<<":ans="<<ans<<",rec="<<rec<<",Ind="<<Ind<<endl;

		while(Ind>0&&stk[Ind]<tem)
			Ind--;
		stk[++Ind]=tem;
	}
	cout<<ans<<endl;
	return 0;
}
