#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
struct ant {
  int id;
  int d;
  int p;
  bool operator < (const ant & a) const {
    return p < a.p;
  }
};
char str[][10] = {"R", "Turning", "L"};
int order[maxn];
ant before[maxn], after[maxn];
int main()
{
  ios::sync_with_stdio(false);
  int tt, kase = 1;
  cin >> tt;
  while (tt--) {
    int l, t, n;
    cin >> l >> t >> n;
    for (int i = 0; i < n; i++) {
      int c; char s;
      cin >> c >> s;
      before[i].id = i;
      before[i].d = s == 'R' ? -1 : 1;
      before[i].p = c;
      after[i].id = 0;
      after[i].p = s == 'R' ? c + t : c - t;
      after[i].d = s == 'R' ? -1 : 1;
    }
    printf("Case #%d:\n", kase++);
    sort(before, before + n);
    for (int i = 0; i < n; i++) {
      order[before[i].id] = i;
    }
    sort(after, after + n);
    for (int i = 0; i < n - 1; i++) {
      if (after[i].p == after[i + 1].p)
        after[i].d = after[i + 1].d = 0;
    }
    for (int i = 0; i < n; i++) {
      int t = order[i];
      if (after[t].p >= 0 && after[t].p <= l) {
        printf("%d %s\n", after[t].p, str[after[t].d + 1]);
      } else {
        printf("Fell off\n");
      }
    }
    printf("\n");
  }
  return 0;
}
