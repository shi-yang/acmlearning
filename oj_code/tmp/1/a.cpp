#include <bits/stdc++.h>
using namespace std;
int a[6][5] = {{0, 1, 2}, {1, 0, 2}, {1, 2, 0}, {2, 1, 0}, {2, 0, 1}, {0, 2, 1}};
int main()
{
  int n, x;
  cin >> n >> x;
  if (n > 5) {
    n %= 6;
  }
  cout << a[n][x] << endl;
  return 0;
}
