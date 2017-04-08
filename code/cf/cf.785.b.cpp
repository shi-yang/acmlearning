#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int mx1 = -1, mi1 = 1e9;
  int mx2 = -1, mi2 = 1e9;
  int a, b;
  while (n--) {
    cin >> a >> b;
    mi1 = min(b, mi1);
    mx2 = max(mx2, a);
  }
  cin >> n;
  while (n--) {
    cin >> a >> b;
    mx1 = max(a, mx1);
    mi2 = min(b, mi2);
  }
  int t1 = mx1 - mi1, t2 = mx2 - mi2;
  if (t1 < 0 && t2 < 0)
    cout << 0 << endl;
  else {
    if (t1 > t2)
      cout << t1 << endl;
    else
      cout << t2 << endl;
  }
  return 0;
}
