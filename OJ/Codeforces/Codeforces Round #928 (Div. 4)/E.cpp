#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 2e5 + 10;
bool vis[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n = 1000, k, ans;
	/*for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j += 2 * i) {
			if (vis[j])
				continue;
			fprintf(stderr, "%d ", j);
			vis[j] = 1;
		}
		fprintf(stderr, "\n");
	}*/
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		ll f = 1, pre = 0;
		while (k > 0)
		{
			ll now = (n - f + 1 + 2 * f - 1) / (2 * f);
			//fprintf(stderr, "f = %lld, now = %lld, k = %lld\n", f, now, k);
			if (k <= now)
			{
				ans = f * (2 * k - 1);
			}
			k -= now;
			f <<= 1;
		}
		cout << ans << endl;
	}

	return 0;
}

