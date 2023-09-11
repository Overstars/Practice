#include<bits/stdc++.h>
using namespace std;
int arr[105],cnt[105],vis[105];
int main()
{
	int n,lim=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		lim=max(lim,arr[i]);
		cnt[arr[i]]++;//数量为奇,贡献+1
	}
	int a=0,b=0;
	for(int i=1;i<=lim;i++)
		if(cnt[i]==1)
			a++;
		else if(cnt[i]>=3)
			b++;
	if(a&1&&!b)
		cout<<"NO\n";
	else{
		cout<<"YES\n";
		int ca=0,cb=0;
		if(a&1)//拿出来一个b
		{
			int mass=0;
			for(int i=1;i<=n;i++)
			{
				if(cnt[arr[i]]==2)
					cout<<"A";//随便
				else if(cnt[arr[i]]==1)
				{
					if(ca<cb)
					{
						cout<<"A";
						ca++;
					}
					else{
						cout<<"B";
						cb++;
					}
				}
				else if(cnt[arr[i]]>2&&!mass)
				{
					cout<<"A";
					ca++;
					mass=arr[i];
				}
				else if(mass==arr[i])
				{
					cout<<"B";//分给另一个
				}
				else{
					cout<<"A";//堆在一起,没有贡献
				}
			}
		}
		else{
			for(int i=1;i<=n;i++)
			{
				if(cnt[arr[i]]==1)//多余的全部无效化
				{
					if(ca<cb)
					{
						cout<<"A";
						ca++;
					}
					else{
						cout<<"B";
						cb++;
					}
				}
				else
					cout<<"A";
			}
		}
	}
	return 0;
}
