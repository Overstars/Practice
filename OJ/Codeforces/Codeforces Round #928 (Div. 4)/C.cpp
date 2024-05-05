#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 2e5 + 10;
ll f[maxn] = {0, 1};
ll func(ll x)
{
	ll ans = 0;
	while (x)
	{
		ans += x % 10;
		x /= 10;
	}
	return ans;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 1; i < maxn ; i++)
		f[i] = f[i-1] + func(i);
	/*for (ll i = 1; i <= 100; i++)
		fprintf(stderr, "f[%lld] = %lld\n", i, func(i));*/
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << f[n] << endl;
	}

	return 0;
}

