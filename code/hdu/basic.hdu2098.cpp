#include <iostream>
using namespace std;
const int maxn = 10000;
int primes[maxn];
int v[maxn];
void getprimes()
{
  for (int i = 2; i <= maxn; i++)
    primes[i] = true;
  int cnt = 0;
  for (int i = 2; i <= maxn; i++) {
    if (primes[i]) {
      v[cnt++] = i;
      for (int j = 2; j * i <= maxn; j++) {
        primes[i * j] = false;
      }
    }
  }
}
int main()
{
  int n;
  getprimes();
  while (scanf("%d", &n) && n) {
    int ans = 0;
    v[0] = 2;
    for (int i = 0;; i++) {
      if (v[i] >= (n >> 1))
       break;
      if (n > v[i] && primes[n - v[i]]) {
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
