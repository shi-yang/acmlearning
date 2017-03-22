#include <bits/stdc++.h>
using namespace std;
int main()
{
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  int t, x;
  cin >> x;
  n--;
  int ans = 1;
  while (n--) {
    int a;
    cin >> a;
    if (a == x) {
      continue;
    } else {
      ans++;
      x = a;
    }
  }
  cout << ans << endl;
  return 0;
}
