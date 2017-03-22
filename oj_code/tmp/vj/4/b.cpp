#include <bits/stdc++.h>
using namespace std;
int a[205];
int b[205];
set<int> s1;
set<int> s2;
struct edge {
  int v, pos, l;
} e[205];
bool cmp1(edge a, edge b)
{
  return a.v > b.v;
}
bool cmp2(edge a, edge b)
{
  return a.pos < b.pos;
}
int main()
{
  int n;
  cin >> n;
  memset(b, 0, sizeof(b));
  for (int i = 0; i < 2 * n; i++) {
    cin >> e[i].v;
    b[e[i].v]++;
    e[i].pos = i;
  }
  sort(e, e + n * 2, cmp1);
  for (int i = 0; i < 2 * n; i++) {
    if (i & 1) {
      e[i].l = 2;
      s1.insert(e[i].v); // min
    } else {
      e[i].l = 1;
      s2.insert(e[i].v); // max
    }
  }
  for (int i = 0; i < s1.size(); i++) {
    if (b[e[i].v] == 1) {
      e[i].l = 1;
    }
  }
  for (int i = n - 1; i >= 2 * n - s2. size(); i--) {
    if (b[e[i].v] == 1)
      e[i].l = 2;
  }
  cout << s1.size() * s2.size() << endl;
  sort(e, e + n * 2, cmp2);
  for (int i = 0; i < 2 * n; i++) {
    cout << e[i].l << ' ';
  }
  return 0;
}
