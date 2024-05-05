#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 2e5 + 10;
int n = 7;
int nx[] = {-1, -1, 1, 1}, ny[] = {-1, 1, -1, 1};
char s[100][100];
bool check (int x, int y)
{
	if (s[x][y] == 'W')
		return false;
	int cnt = 0;
	for (int i = 0 ; i < 4; i++)
	{
		int xx = x + nx[i], yy = y + ny[i];
		if (xx < 1 || xx > n || yy < 1 || yy > n)
			continue;
		if (s[xx][yy] == 'B')
			cnt++;
	}
	return cnt == 4;
}
bool over()
{
	bool ok = true;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (check(i, j))
				return false;
	return ok;
}
void inc(int x, int y, map<pii, int> &cnt)
{
	cnt[pii(x, y)]++;
	for (int i = 0 ; i < 4; i++)
	{
		int xx = x + nx[i], yy = y + ny[i];
		cnt[pii(xx, yy)]++;
	}
}
struct node
{
	int x, y, cnt;
	bool operator <(const node &r)const{
        return cnt > r.cnt;
    }
};
pii getnext()
{
	map<pii, int> cnt; //每个点的权重
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (check(i, j))
				inc(i, j, cnt);
		}
	}
	vector<node> v;
	for (auto &i : cnt)
		v.push_back(node{i.first.first, i.first.second, i.second});
	sort(v.begin(), v.end());
	return make_pair(v[0].x, v[0].y); 
}
void show()
{
	for (int i = 1; i <= n; i++)
		fprintf(stderr, "%s\n", s[i] + 1);
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		for (int i = 1; i <= 7; i++)
			cin >> s[i] + 1;
		int ans = 0, l = 0, r = 49;
		while(!over())
		{
			pii a = getnext();
			//fprintf(stderr, "nex = [%d, %d]\n", a.first, a.second);
			s[a.first][a.second] = 'W';
			//show();
			ans ++;
		}
		
		cout << ans << endl;
	}

	return 0;
}
/*
1
BBBBBBB
BBBBBBB
BBBBBBB
BBBBBBB
BBBBBBB
BBBBBBB
BBBBBBB
 *
 *
 */

