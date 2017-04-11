#include <bits/stdc++.h>
using namespace std;
const int maxn = 300005;
int b[maxn];
struct edge {
  int id, v;
  bool operator < (const edge & a) const {
    return v < a.v;
  }
} e[maxn];
int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &e[i].v);
    e[i].id = i;
  }
  sort(e, e + n);
  b[e[0].id] = e[0].v;
  int tmp = e[0].v;
  for (int i = 1; i < n; i++) {
    if (e[i].v <= tmp) {
      b[e[i].id] = ++tmp;
    } else {
      tmp = b[e[i].id] = e[i].v;
    }
  }
  for (int i = 0; i < n; i++) {
    if (i)
      printf(" ");
    printf("%d", b[i]);
  }
  printf("\n");
  return 0;
}
