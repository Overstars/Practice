#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
int hpsiz=0;
int arr[maxn];
bool jud1(int x)
{
	return arr[0]==x;
}
bool jud2(int x,int y)
{
	int l=0,r=0;
	for(int i=0;i<hpsiz;i++)
	{
		if(arr[i]==x)
			l=i;
		if(arr[i]==y)
			r=i;
	}
	if(l>r)
		swap(l,r);
//	printf("%d,%d兄弟\n",l,r);
	return (l%2&&r==l+1);
}
bool jud3(int x,int y)
{//x是y的父节点
	int l=0,r=0;
	for(int i=0;i<hpsiz;i++)
	{
		if(arr[i]==x)
			l=i;
		if(arr[i]==y)
			r=i;
	}
	return (r==l*2+1||r==l*2+2);
}
bool jud4(int x,int y)
{
	int l=0,r=0;
	for(int i=0;i<hpsiz;i++)
	{
		if(arr[i]==x)
			l=i;
		if(arr[i]==y)
			r=i;
	}
	return (l==r*2+1||l==r*2+2);
}
bool (*ans[5])(int,int)={NULL,NULL,jud2,jud3,jud4};
void justify(int x)//小顶堆
{
	int lc=2*x+1,rc=2*x+2,mi;
	if(lc<hpsiz&&arr[lc]<arr[x])
		mi=lc;
	else
		mi=x;
	if(rc<hpsiz&&arr[rc]<arr[mi])
		mi=rc;
	if(mi!=x)
	{
		swap(arr[x],arr[mi]);
		justify(mi);//向下调整
	}
}
void build(int n)//
{
	hpsiz=n;
	for(int i=hpsiz/2-1;i>=0;i--)
		justify(i);
}
void Insert(int num)
{
	arr[hpsiz]=num;//插入堆尾
	int i=hpsiz;
	for(int j=(hpsiz-1)/2;j>=0&&i!=0;i=j,j=(i-1)/2)
	{
		if(arr[j]<=num)
			break;
		arr[i]=arr[j];
	}
	arr[i]=num;
	hpsiz++;
}
int main()
{
	int n,m,num;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>num;
		Insert(num);
	}
	while(m--)
	{
		int x,y,ope;
		string s1,s2,s3;
		cin>>x>>s1;
		if(s1[0]=='a')
		{
			ope=2;
			cin>>y>>s2>>s3;
		}
		else{
			cin>>s1;
			if(s1[0]=='a')
			{
				ope=4;
				cin>>s1>>s2>>y;
			}
			else{
				cin>>s1;
				if(s1[0]=='r')
				{
					ope=1;
				}
				else{
					ope=3;
					cin>>s2>>y;
				}
			}
		}
		if(ope==1)
			cout<<(jud1(x)?"T":"F")<<endl;
		else{
			cout<<(ans[ope](x,y)?"T":"F")<<endl;
		}
	}
	return 0;
}
