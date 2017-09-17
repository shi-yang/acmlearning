#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 8006;
int color[N];
int cnt[N];
int main()
{
  int n;
  while (~scanf("%d", &n)) {
    memset(color, -1, sizeof(color));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
      int l, r, c;
      scanf("%d %d %d", &l, &r, &c);
      for (int j = l; j < r; j++)
        color[j] = c;
    }
    if (color[0] != -1) {
      cnt[color[0]]++;
    }
    for (int i = 1; i < N; i++) {
      if (color[i] != -1 && color[i - 1] != color[i]) {
        cnt[color[i]]++;
      }
    }
    for (int i = 0; i <= N; i++) {
      if (cnt[i]) {
        printf("%d %d\n", i, cnt[i]);
      }
    }
    puts("");
  }
  return 0;
}