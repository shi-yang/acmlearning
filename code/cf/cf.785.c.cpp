#include <bits/stdc++.h>
using namespace std;
int main()
{
  long long n, m;
  cin >> n >> m;
  if (m >= n) {
    cout << n << endl;
  } else {
    long long t = sqrt(2 * (n - m));
    if((t * (t + 1)) / 2 + m >= n)
      cout << m + t << endl;
    else
      cout << m + t + 1 << endl;
  }
  return 0;
}
