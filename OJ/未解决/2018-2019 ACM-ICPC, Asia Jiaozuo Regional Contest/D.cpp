#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#define int long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define MEM(x,y) memset(x,y,sizeof(x))
#define rep(i , a , b) for(int i = a ; i <= b ; i ++)
#define sc(a) scanf("%lld",&a)
#define pf(a) printf("%lld ",a)
#define db double
#define PI acos(-1)
using namespace std;


typedef pair<int, int>pii;

const int N = 5000 + 200, INF = 0x3f3f3f3f3f3f3f3f, MOD = 1e9 + 7;




int T;


int n;

int a[5];


signed main() {

	sc(T);

	while (T--) {

		double a, b, r, d;

		scanf("%lf %lf %lf %lf", &a, &b, &r, &d);

		d = d * PI / 180;

		db l = sqrt(b * b + (a + r) * (a + r));

		db d1 = asin(b / l);
		db ans;
		if (d >= d1)ans = l - r;
		else  ans = l * cos(d1 - d) - r;

		printf("%.9f\n", ans);



	}

}
