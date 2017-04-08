#include <bits/stdc++.h>
using namespace std;
int main()
{
  int m, a[105], x, y;
  scanf("%d", &m);
  int sum = 0;
  for (int i = 0; i < m; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  scanf("%d %d", &x, &y);
  int tmp = 0;
  for (int i = 0; i < m; i++) {
    tmp += a[i];
    if (x <= tmp && tmp <= y && sum - tmp >= x && sum - tmp <= y) {
      printf("%d\n", i + 2);
      return 0;
    }
  }
  printf("0\n");
  return 0;
}
