#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>//�������,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
const int inf=0x3f3f3f3f;
//���:https://blog.csdn.net/qq1965610770/article/details/80041940
//#define DEBUG
int a[200005],pos[200005],full[200005];//ԭ����
//pos[i]:i��a�����г��ֵ����һ��λ��
//full[j]:������iʱ,full[j]��ʾ�Ѿ�������0~j������[x,i]��x�����ֵ
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	int n;
	while(cin>>n&&n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		memset(pos,0,sizeof(pos));
		memset(full,0,sizeof(full));
		long long inc=0,ans=0;//��i��:inc��ʾ[1,i]~[i,i]��mec�ĺ�
		int last;//��¼ĳ�����ϴγ��ֵ�λ��
		for(int i=1;i<=n;i++)
		{
			//������һ��inc�Ƴ���һ��inc
			if(a[i]<n)//���ڵ���n��������Ե�ǰ�����Ӱ��
			{
				last=pos[a[i]];//a[i]�ϴγ��ֵ�λ��
				pos[a[i]]=i;//����pos
				//��������(last,i],a[i]����last֮ǰ��������Ӱ��
				for(int j=a[i];j<n;j++)//���������Ӱ�������a[i]~n,��Щ����mex���ܻᷢ���仯
				{
					if(j)
						full[j]=min(full[j-1],pos[j]);//��֤����[full[j],i]�Ѿ�������0~j
					else//pos[j]������?
						full[0]=i;
					if(full[j]>last)//��last֮ǰ��������Ӱ��
						inc+=full[j]-last;//(last,full[j]]�ڵ�����mex+1
					else
						break;
				}
			}
			ans+=inc;
		}
		cout<<ans<<endl;
	}
	return 0;
}
