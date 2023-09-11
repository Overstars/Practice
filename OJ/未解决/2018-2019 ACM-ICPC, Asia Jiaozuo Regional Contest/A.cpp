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
using namespace std;


typedef pair<int, int>pii;

const int N = 5000 + 200, INF = 0x3f3f3f3f3f3f3f3f, MOD = 1e9 + 7;



int T;


int n;

int a[5];


signed main() {
//	IOS
	cin >> T;


	while (T--) {

		rep(i, 1, 4)cin >> a[i];

		int rem = 0;

		rep(i, 1, 4) {
			if (a[i] > 0)rem++;
		}
		if (rem == 0)cout << "Typically Otaku" << '\n';
		else if (rem == 1)cout << "Eye-opener" << '\n';
		else if (rem == 2)cout << "Young Traveller" << '\n';
		else if (rem == 3)cout << "Excellent Traveller" << '\n';
		else if (rem == 4)cout << "Contemporary Xu Xiake" << '\n';


	}

}
