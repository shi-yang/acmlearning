#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
  int a, b;
  while (cin >> a >> b) {
    if (a > b)
      swap(a, b);
    int k = b - a;
    if (a == int(1.0 * k * (sqrt(5.0) + 1) / 2)) {
      cout << 0 << endl;
    } else {
      cout << 1 << endl;
    }
  }
  return 0;
}