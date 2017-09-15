#include <iostream>
#include <map>
#include <cstdio>
#include <cmath>
using namespace std;
const double g = (sqrt(5.0) + 1) / 2.0;
bool check(int a, int b)
{
  return a == int((b - a) * g);
}
int main()
{
  int a, b;
  while (cin >> a >> b && a + b) {
    if (a > b)
      swap(a, b);
    int k = b - a;
    if (check(a, b)) {
      cout << 0 << endl;
    } else {
      cout << 1 << endl;
      for (int i = 1; i <= a; i++) {
        if (check(a - i, b - i)) {
          cout << a - i << ' ' << b - i << endl;
        }
      }
      for (int i = 1; i <= a; i++) {
        int x = a, y = b - i;
        if (x > y)
          swap(x, y);
        if (check(x, y)) {
          cout << x << ' ' << y << endl;
          break;
        }
      }
    }
  }
  return 0;
}