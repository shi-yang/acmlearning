/*
 * 组合数学题，边乘的同时边做除法，不然会超范围。
 */
#include <iostream>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    long long ans = 1;
    if (n < m) {
      cout << 0 << endl;
      continue;
    }
    for (int i = 1; i <= m; i++) {
      ans *= (n--);
      ans /= i;
    }
    cout << ans << endl;
  }
	return 0;
}
