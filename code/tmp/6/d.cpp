#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  long a[1000];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++) {
    int x, y;
    x = y = 0;
    for (int j = i + 2; j < n; j++) {
      if ((a[j] > a[i] && a[j] > a[i + 1]) || a[j] < a[i] && a[j] < a[i + 1])
        x++;
      else
        y++;
    }
    if (x && y) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
