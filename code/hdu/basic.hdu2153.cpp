/**
 * 用四个循环依次把边框的数填到一个二维数组中就得了。
 */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[10][10];
int main()
{
  int n;
  while (cin >> n) {
    int x = 0, y = 0;
    memset(a, 0, sizeof(a));
    int tot = 1;
    a[x][y] = tot;
    while (y + 1 < n)
      a[x][++y] = ++tot;
    while (x + 1 < n)
      a[++x][y] = ++tot;
    while (y > 0)
      a[x][--y] = ++tot;
    while (x > 1)
      a[--x][y] = ++tot;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0 || i == n - 1) {
          printf("%3d", a[i][j]);
        } else {
          if (j == 0 || j == n - 1) {
            printf("%3d", a[i][j]);
          } else {
            printf("   ");
          }
        }
      }
      printf("\n");
    }
  }
  return 0;
}
