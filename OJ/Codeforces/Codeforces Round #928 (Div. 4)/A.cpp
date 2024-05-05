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
		map<char, int> mp;
		string s;
		cin >> s;
		for (char &ch : s)
			mp[ch] ++;
		cout << (mp['A'] > mp['B'] ? 'A' : 'B') << endl;
	}

	return 0;
}
