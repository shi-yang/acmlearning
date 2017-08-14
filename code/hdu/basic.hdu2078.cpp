#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int f = 999;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      f = min(a, f);
    }
    int ans = (100 - f) * (100 - f);
    cout << ans << endl;
  }
  return 0;
}
