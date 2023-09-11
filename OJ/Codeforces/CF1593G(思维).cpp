#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
char s[maxn];
int cntodd[maxn],cnteven[maxn];
int main()
{
	int t,q;
	cin >> t;
	while(t--)
	{
		cin >> s+1 >> q;
		int n = strlen(s+1);
		for(int i = 1 ; i <= n ; i ++ )
		{
			cntodd[i] = cnteven[i] = 0;
			if(s[i] == '[' || s[i] == ']')
			{
				if(i&1)
					cntodd[i]++;
				else
					cnteven[i]++;
			}
			cntodd[i] += cntodd[i-1];
			cnteven[i] += cnteven[i-1];
		}
		while(q--)
		{
			int l,r;
			cin >> l >> r;
			int even = cnteven[r] - cnteven[l-1], odd = cntodd[r] - cntodd[l-1];
			int ans = max(even,odd)-min(even,odd);
			cerr << "ans = ";
			cout << ans << endl;
		}
	}
	return 0;
}
/*
 * 如果一段区间内奇数下标方括号数目=偶数下标方括号数目，那么ans=0
 * 合法 -> 数目相等
 * 因为其内部总是一个合法括号段，长度为偶数
 * 匹配的右括号为pos+偶数+1，性质与pos不同
 * 所以合法的括号序列，奇数下标方括号数目=偶数下标方括号数目
 * 数目相等 -> 合法
 * 找到最左面的方括号，和最右面的方括号进行匹配，会将这一段分割为三部分
 * 进行归纳下去，都是合法括号
 */
