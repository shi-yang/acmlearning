#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
  int m, n;
  while (~scanf("%d %d", &m, &n)) {
    if (n >= m) {
      for (int i = m; i <= n; i++) {
        printf("%d", i);
        if (i != n) {
          printf(" ");
        }
      }
      puts("");
      continue;
    }
    int c = m % (n + 1);
    if (c) {
      printf("%d\n", c);
    } else {
      puts("none");
    }
  }
  return 0;
}