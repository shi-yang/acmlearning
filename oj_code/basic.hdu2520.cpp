#include <iostream>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ans = 0;
    int s = 1;
    for (int i = 1; i <= n; i++) {
      ans += s;
      s += 2;
      ans %= 10000;
    }
    cout << ans << endl;
  }
  return 0;
}
