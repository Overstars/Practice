#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[500005];
int main()
{
    int l,m,n,i;//������Թ����������Ծ����
    while(cin>>l>>n>>m){//�ӿ�l,n��ʯͷ,�����m��
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		a[n+1]=l;
		sort(a,a+n+2);
		int maxn=0;
		for(i=1;i<=n+1;i++)
			maxn=max(maxn,a[i]-a[i-1]);
		int left=maxn,right=l,mid;//midΪ����Ĳ���
		while(left<=right){
			int pos=0,cnt=0;//�Ӱ�����,���Ĵ���
			mid=(left+right)/2;
			for(i=1;i<=n;i++)
				if(a[i]-a[pos]<=mid&&a[i+1]-a[pos]>mid)
				{
					pos=i;
					cnt++;//��һ��
				}
			cnt++;//�����԰�
			if(cnt<=m)//��Ͳ�������,û�г�����ò���
				right=mid-1;
			else//���貽������,�Ӵ󲽳�
				left=mid+1;
		}
		printf("%d\n",left);
    }
    return 0;
}
