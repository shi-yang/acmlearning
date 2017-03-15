#include <cstdio>
#include <algorithm>
using namespace std;
struct edge {
  int a, b;
} e[25005];
bool cmp(edge x, edge y)
{
  return x.a < y.a;
}
int main()
{
  int n, t;
  scanf("%d%d", &n, &t);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &e[i].a, &e[i].b);
  }
  sort(e, e + n, cmp);
  int l = 0, cnt = -1, ans = 0;
  while (l < t) {
    int mxr = -1, mxri;
    while (e[++cnt].a <= l + 1)
      mxr = e[cnt].b > mxr ? e[mxri = cnt].b : mxr;
    if(mxr == -1){
      ans = -1;
      break;
    }
    ans++;
    cnt--;
    l = mxr;
  }
  printf("%d\n", ans);
  return 0;
}
