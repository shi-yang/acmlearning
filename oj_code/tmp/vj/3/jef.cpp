#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n, a, b, x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x == 5)
      a++;
    else
      b++;
  }
  int pos, flag = true;
  for (int i = a; i >= 0; i--) {
    int sum = i * 5;
    if (sum % 9 == 0) {
      pos = i;
      flag = false;
      break;
    }
  }
  if (flag && b == 0) {
    cout << -1 << endl;
    return 0;
  }
  if (pos == 0 && b > 0) {
    cout << 0 << endl;
  } else {
    while (pos--) cout << 5;
    while (b--) cout << 0;
    cout << endl;
  }
  return 0;
}
