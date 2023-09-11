#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define PB push_back
#define eps 1e-10
struct Point {
  double x, y;
  Point(double x, double y) {
    this->x = x;
    this->y = y;
  }
  Point() { x = y = 0; }
};
Point p[5000];
Point solve(Point a, Point b, Point c) {
  double X, Y;
  X = ((a.x * a.x - b.x * b.x + a.y * a.y - b.y * b.y) * (a.y - c.y) -
       (a.x * a.x - c.x * c.x + a.y * a.y - c.y * c.y) * (a.y - b.y)) /
      (2 * (a.y - c.y) * (a.x - b.x) - 2 * (a.y - b.y) * (a.x - c.x));
  Y = ((a.x * a.x - b.x * b.x + a.y * a.y - b.y * b.y) * (a.x - c.x) -
       (a.x * a.x - c.x * c.x + a.y * a.y - c.y * c.y) * (a.x - b.x)) /
      (2 * (a.y - b.y) * (a.x - c.x) - 2 * (a.y - c.y) * (a.x - b.x));
  return Point(X, Y);
}
vector<pair<double, double>> m;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lf%lf", &p[i].x, &p[i].y);
  }
  Point z(0, 0);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (fabs(p[i].x * p[j].y - p[i].y * p[j].x) > eps) {
        Point temp = solve(p[i], p[j], z);
        m.PB({temp.x, temp.y});
      }
    }
  }
  int cnt = 0, maxx = 0;
  sort(m.begin(), m.end());
  if (!m.size()) {
    puts("1");
    return 0;
  }
  int sum = m.size();
  for (int i = 0; i < sum; i++) {
    cnt++;
    if (fabs(m[i].first - m[i + 1].first) > eps ||
        fabs(m[i].second - m[i + 1].second) > eps) {//圆心不同
      maxx = max(maxx, cnt);//最大相同圆心数量
      cnt = 0;
    }
  }
  int ans = 0;
  for (ans = 1; ans <= n; ans++) {
    if (ans * (ans - 1) == 2 * maxx) {
      break;
    }
  }
  printf("%d\n", ans);
  return 0;
}
