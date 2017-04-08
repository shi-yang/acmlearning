#include <bits/stdc++.h>
using namespace std;
const int maxn = 15;
char G[maxn][maxn];
int main()
{
  int t, n;
  scanf("%d", &t);
  for (int kase = 1; kase <= t; kase++) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%s", &G[i]);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (G[i][j] == '.') {
          for (char ch = 'A'; ch <= 'Z'; ch++) {
            int ok = 1;
            if (i > 0 && G[i - 1][j] == ch)
              ok = 0;
            if (i < n - 1 && G[i + 1][j] == ch)
              ok = 0;
            if (j < n - 1 && G[i][j + 1] == ch)
              ok = 0;
            if (j > 0 && G[i][j - 1] == ch)
              ok = 0;
            if (ok) {
              G[i][j] = ch;
              break;
            }
          }
        }
      }
    }
    printf("Case %d:\n", kase);
    for (int i = 0; i < n; i++) {
      printf("%s\n", G[i]);
    }
  }
  return 0;
}
