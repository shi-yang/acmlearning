#include <bits/stdc++.h>
using namespace std;
int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  if (!a || !b || !c) {
    cout << "Impossible" << endl;
    return 0;
  }
  float x = (a + b - c) / 2.0;
  float y = (b + c - a) / 2.0;
  float z = (a + c - b) / 2.0;
  if ((!x && !y) || (!x && !z) || (!y && !z)) {
    cout << "Impossible" << endl;
    return 0;
  }
  if (x == (int)x && y == (int)y && z == (int)z && x >= 0 && y >= 0 && z >= 0) {
    cout << x << ' ' << y << ' ' << z << endl;
  } else {
    cout << "Impossible" << endl;
  }
  return 0;
}
