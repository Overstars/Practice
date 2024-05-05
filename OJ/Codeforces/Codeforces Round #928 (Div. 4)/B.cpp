#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 20, inf = 0x3f3f3f3f;
char s[maxn][maxn];
struct node 
{
	int x, y;
} pt[4];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		pt[0].x = pt[0].y = pt[1].x = pt[2].y = inf;
		pt[1].y = pt[2].x = pt[3].x = pt[3].y = -inf;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> s[i] + 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (s[i][j] == '1')
				{
					if (i <= pt[0].x)
						pt[0].x = min(pt[0].x, i), pt[0].y = min(pt[0].y, j);
					if (i <= pt[1].x)
						pt[1].x = min(pt[1].x, i), pt[1].y = max(pt[1].y, j);
					if (i > pt[2].x)
						pt[2].x = i, pt[2].y = j;
					else
						pt[2].x = i, pt[2].y = min(pt[2].y, j);
					if (i > pt[3].x)
						pt[3].x = i, pt[3].y = j;
					else
						pt[3].x = i, pt[3].y = max(pt[3].y, j);
				}
			}
		}
		/*for (int i = 0; i < 4; i++) {
			fprintf(stderr, "pt[%d] = [%d, %d]\n", i, pt[i].x, pt[i].y);
		}*/
		bool flag = false;
		if (pt[0].x == pt[1].x && pt[0].y == pt[2].y && pt[1].y == pt[3].y && pt[2].x == pt[3].x)
			flag = true;
		cout << (flag ? "SQUARE" : "TRIANGLE") << endl;
	}

	return 0;
}

