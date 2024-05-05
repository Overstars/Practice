#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 2e5 + 10;
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		map<int, int> mp;
		int ans = n, x;
		for (int i = 0; i < n; i++) {
			cin >> x;
			int y = (~x) & ((1<<31) -1);
			//bitset<32> xx(x), yy(y);
			//cout << xx << " " << yy << endl;
			if (mp[y] > 0) {
				mp[y] --;
				ans--;
			} else {
				mp[x] ++;
			}
		}
		cout << ans << endl;
	}

	return 0;
}

