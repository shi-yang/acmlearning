#include <bits/stdc++.h>
using namespace std;
int f[20];
int sg[1005], s[1005];
int main()
{
  f[0] = 1, f[1] = 2;
  for (int i = 2; i < 20; i++)
    f[i] = f[i - 1] + f[i - 2];
  for (int i = 1; i < 1005; i++) {
    memset(s, 0, sizeof(s));
    for (int j = 0; f[j] <= i; j++) {
      s[sg[i - f[j]]] = 1;
    }
    for (int j = 0; ; j++) {
      if (!s[j]) {
        sg[i] = j;
        break;
      }
    }
  }
  int m, n, p;
  while (cin >> m >> n >> p && m + n + p) {
    if (sg[m] ^ sg[n] ^ sg[p]) {
      puts("Fibo");
    } else {
      puts("Nacci");
    }
  }
  return 0;
}