#include <bits/stdc++.h>
int main()
{
  int n, m;
  int a, b, c, x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    a = min(a, x);
    b = max(b, x);
  }
  for (int i = 0; i < n; i++) {
    cin >> x;
    c = min(c, x);
  }
  a = max(2 * a, b);
  if (a < c)
    cout << a << endl;
  else
    cout << -1 << endl;
  return 0;
}
