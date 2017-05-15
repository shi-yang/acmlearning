#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
char s[maxn], t[maxn], ans[maxn];
int main()
{
  cin >> s >> t;
  int n = strlen(s);
  sort(s, s + n);
  sort(t, t + n);
  reverse(t, t + n);
  int sl = 0, sr = n + 1 >> 1, tl = 0, tr = n >> 1, cl = 0, cr = n;
  for (int i = 0; i < n; i++) {
    if (i & 1) {
      if (t[tl] > s[sl])
        ans[cl++] = t[tl++];
      else
        ans[--cr] = t[--tr];  
    } else {
      if (t[tl] > s[sl])
        ans[cl++] = s[sl++];
      else
        ans[--cr] = s[--sr];
    }
  }
  printf("%s\n", ans);
  return 0;
}