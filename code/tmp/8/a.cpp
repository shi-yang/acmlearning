#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[1005];
int main()
{
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      a[x]++;
    }
    int cnt = -1;
    int flag = 0;
    int pos = 0;
    for (int i = 1; i <= 1000; i++) {
      if (cnt < a[i]) {
        cnt = a[i];
        pos = i;
      }
    }
    for (int i = 1; i <= 1000; i++) {
      if (i != pos && a[i] == cnt) {
        flag = 1;
      }
    }
    if (flag) {
      printf("Nobody\n");
    } else {
      printf("%d\n", pos);
    }
  }
  return 0;
}
