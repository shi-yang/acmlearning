#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int x;
  bool can = true;
  int a = 0, b = 0;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x == 25) {
      a++;
    } else if (x == 50) {
      b++, a--;
    } else if (x == 100) {
      if (a > 0 && b > 0) {
        a--, b--;
      } else {
        a -= 3;
      }
    }
    if (a < 0 || b < 0) {
      can = false;
    }
  }
  if (can) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
