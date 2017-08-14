#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 105;
int tower[maxn][maxn];

int max(int a, int b)
{
  return a > b ? a : b;
}
int main()
{
  int c;
  scanf("%d", &c);
  while (c--) {
    int n;
    scanf("%d", &n);
    memset(tower, 0, sizeof(tower));
    for (int i = 0; i < n; i++)
      for (int j = 0; j <= i; j++)
        scanf("%d", &tower[i][j]);
    for (int i = n - 1; i >= 0; i--)
      for (int j = 0; j <= i; j++)
        tower[i][j] += max(tower[i + 1][j], tower[i + 1][j + 1]);
    printf("%d\n", tower[0][0]);
  }
  return 0;
}