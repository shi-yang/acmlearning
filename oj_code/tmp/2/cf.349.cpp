#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int a = 0, b = 0;
  bool flag = true;
  while (n--) {
    int x;
    cin >> x;
    if (x == 25) {
      a++;
    } else if (x == 50) {
      a--;
      b++;
    } else if (x == 100) {
      if (a > 0 && b > 0) {
        a--;
        b--;
      } else {
        a -= 3;
      }
    }
    if (a < 0 || b < 0) {
      flag = false;
    }
  }
  if (flag) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
