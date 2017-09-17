#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
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
      printf("No\n");
      continue;
    }
    puts("Yes");
    for (int i = 0; i < m; i++) {
      if ((t ^ a[i]) <= a[i]) {
        printf("%d %d\n", a[i], t ^ a[i]);
      }
    }
  }
  return 0;
}