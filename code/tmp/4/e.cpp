#include <bits/stdc++.h>
using namespace std;
int a[200005];
bool u[200005];
string t, p;
bool c(int m)
{
  memset(u, false, sizeof(u));
  for (int i = 0; i < m; i++) {
    u[a[i]] = 1;
  }
  int pos = 0;
  for (int i = 0; i < t.size(); i++) {
    if (!u[i] && t[i] == p[pos]) {
      pos++;
      if (pos == p.size())
        return true;
    }
  }
  return false;
}
int main()
{
  //freopen("in", "r", stdin);
  cin >> t >> p;
  int x;
  for (int i = 0; i < t.size(); i++)
    cin >> x, a[i] = x - 1;
  int l = 0, r = t.size() + 1;
  while (r - l > 1) {
    //cout << l << ' ' << r << endl;
    int m = (r + l) >> 1;
    if (c(m)) {
      l = m;
    } else {
      r = m;
    }
  }
  cout << l << endl;
  return 0;
}
