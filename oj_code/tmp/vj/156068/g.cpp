#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 200005;
int st[maxn], h[maxn], R[maxn], L[maxn];
int main()
{
  int n;
  cin >> n;
  int t = 0;
  for (int i = 0; i < n; i++) {
    cin >>
  }
  for (int i = 0; i < n; i++) {
    while (t > 0 && h[st[t - 1]] >= h[i])
      t--;
    L[i] = t == 0 ? 0 : (st[t - 1] + 1);
    s[t++] = i;
  }
  t = 0;
  for (int i = n - 1; i >= 0; i--) {
    while (t > 0 && h[st[t - 1]] >= h[i])
      t--;
    R[i] = t == 0 ? n : st[t - 1];
    st[t++] = i;
  }
  long long res = 0;
  for (int i = 0; i < n; i++) {
    res = max(res, (long long)h[i] * (R[i] - L[i]));
  }
  cout << res << endl;
  return 0;
}
