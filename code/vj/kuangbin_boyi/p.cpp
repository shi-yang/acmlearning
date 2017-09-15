#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N];
int main()
{
  int m;
  while (~scanf("%d", &m) && m) {
    int t = 0;
    for (int i = 0; i < m; i++) {
      scanf("%d", a + i);
      t ^= a[i];
    }
    if (!t) {
      printf("0\n");
      continue;
    }
    int sum = 0;
    for (int i = 0; i < m; i++) {
      if (t ^ a[i] <= a[i])
        sum++;
    }
    printf("%d\n", sum);
  }
  return 0;
}