#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
  int n;
  freopen("data.in", "r", stdin);
  while (cin >> n && n) {
    int ans = 1e9;
    int t;
    double v;
    for (int i = 0; i < n; i++) {
      cin >> v >> t;
      if (t < 0) {
        continue;
      }
      v = (1.0 * v / 3.6);
      int tmp = ceil(4500 / v);
      ans = min(ans, tmp + t);
    }
    cout << ans << endl;
  }
  return 0;
}
