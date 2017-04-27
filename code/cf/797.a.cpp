#include <bits/stdc++.h>
using namespace std;
int a[100000];
int main()
{
  int n, k;
  cin >> n >> k;
  if (k == 1) {
    cout << n << endl;
    return 0;
  }
  if ((1 << k) > n) {
    cout << -1 << endl;
    return 0;
  }
  int cnt = 0;
  for (int i = 2; i <= n;) {
    if (n % i == 0) {
      a[cnt++] = i;
      n /= i;
      if (cnt == k)
        break;
    } else {
      i++;
    }
  }
  if (cnt < k) {
    cout << -1 << endl;
  } else {
    a[k - 1] *= n;
    for (int i = 0; i < k; i++)
      cout << a[i] << ' ';
  }
  return 0;
}