#include <iostream>
#include <cstdio>
using namespace std;
const double eps = 1e-9;
int main()
{
  int t;
  cin >> t;
  while (t--) {
    double y;
    cin >> y;
    if (y < 6 || y > 807020306) {
      cout << "No solution!" << endl;
      continue;
    }
    double l = 0, r = 100, ans;
    while (r - l > eps) {
      double x = l + (r - l) / 2.0;
      double tmp = 8 * x * x * x * x + 7 * x * x * x + 2 * x * x + 3 * x + 6;
      ans = x;
      if (tmp == y) {
        break;
      }
      if (tmp < y) {
        l = x;
      } else {
        r = x;
      }
    }
    printf("%.4lf\n", ans);
  }
  return 0;
}
