#include <bits/stdc++.h>
using namespace std;
const int N = 65005;
int prime[N];
void init()
{
  memset(prime, -1, sizeof(prime));
  prime[1] = 0;
  for (int i = 2; i < N; i++) {
    if (prime[i]) {
      for (int j = i + i; j < N; j += i) {
        prime[j] = 0;
      }
    }
  }
}
inline int power(int n, int k, int m)
{
  int res = 1;
  while (k) {
    if (k & 1) {
      res = 1LL * res * n % m;
    }
    n = 1LL * n * n % m;
    k >>= 1;
  }
  return res;
}
int main()
{
  int n;
  init();
  while (~scanf("%d", &n) && n) {
    if (prime[n]) {
      printf("%d is normal.\n", n);
      continue;
    }
    int a;
    for (a = 2; a < n; a++) {
      if (power(a, n, n) != a) {
        break;
      }
    }
    if (a >= n) {
      printf("The number %d is a Carmichael number.\n", n);
    } else {
      printf("%d is normal.\n", n);
    }
  }
  return 0;
}