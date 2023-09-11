#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int a[maxn];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];

	return 0;
}
/*
 *https://codeforces.ml/gym/102133/problem/F
 *1e5的数组,你可以选择任意两个位置并交换
 *使得产生的子段和最大
 *输出这个子段和和交换的下标
*/













/*
先dp，和一般的求最大子串和几乎一样
找出以位置i为左起点的子串，但这个允许中途出现一次负值
找到和的最大值
然后那个负值与不在子串的最大元素对调求新的最大值。
然后下次dp起点是中途那个负值的下一数开始。
而区间最大元素你可以线段树来查

*/
