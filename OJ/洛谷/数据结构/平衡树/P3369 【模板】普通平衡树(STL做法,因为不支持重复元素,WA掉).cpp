#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pii pair<int,int>
#define mp(x,y) make_pair(x,y)
int main()
{
//	freopen("P3369.in","r",stdin);
//	freopen("P3369(2).in","r",stdin);
//	freopen("P3369(3).in","r",stdin);
	int n,ope,x;
	cin>>n;
	tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> rbt;
	while(n--)//不支持重复值
	{
		cin>>ope>>x;
		switch(ope)
		{
		case 1://插入
			rbt.insert(x);
			break;
		case 2://删除
			rbt.erase(x);
			break;
		case 3://查询排名
			cout<<rbt.order_of_key(x)+1<<endl;
			break;
		case 4://查询排名为x的数
			cout<<*rbt.find_by_order(x-1)<<endl;
			break;
		case 5://查x前驱
			cout<<*--rbt.lower_bound(x)<<endl;
			break;
		case 6://后继
			cout<<*rbt.upper_bound(x)<<endl;
			break;
		default:
			break;
		}
	}
	return 0;
}
