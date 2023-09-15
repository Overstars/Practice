#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
/*
 *
 */
int main()
{
	int t, n, k;
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		int ans = 0;
		int l = 1, val;
		// greed
		for (l = 1; l + k -1 <= n; l += k)
		{
			cout << l << endl;
			cout.flush();
			cin >> val;
			ans ^= val;
		}
		if (l <= n) 
		{
			cout << "";
			cout.flush();
			cin >> 
		}
		cout << "! " << ans << endl;
		cout.flush();
	}
	return 0;
}
