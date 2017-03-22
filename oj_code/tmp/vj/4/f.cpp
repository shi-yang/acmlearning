#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int main()
{
  cin >> n >> m >> k;
  int tmp = m % n;
  int sum = 1;
  int pos = 0;
  for (int i = 1;; i++) {
    if (k == 1 || k == n) {
      sum += sum + 2;
    } else {
      sum += sum + 1;
    }
    if (sum > tmp) {
      pos = i;
      break;
    }
  }
  pos += m / n;
  cout << pos << endl;
  return 0;
}
