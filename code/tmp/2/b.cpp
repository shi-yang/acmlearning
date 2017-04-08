#include <bits/stdc++.h>
using namespace std;
int a[11];
int main()
{
  int n;
  cin >> n;
  bool f = true;
  int mx = -1, num;
  for (int i = 1; i <= 9; i++) {
    cin >> a[i];
    int t = n / a[i];
    if (mx <= t) {
      mx = t;
      num = i;
    }
    if (n >= a[i]) {
      f = false;
    }
  }
  if (f) {
    cout << -1 << endl;
    return 0;
  }
  int cnt = 0;
  int k;
  int b[9];
  for (int i = 9; num < i && i >=1; i--) {
    int t = a[num] + n % mx;
    if (t >= a[i]) {
      b[cnt++] = i;
    }
  }
  for (int i = 0; i < cnt; i++)
    cout << b[i];
  for (int i = 0; i < mx - cnt; i++)
    cout << num;
  cout << endl;
  return 0;
}
