#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    int ans = a[0] - a[1];
    int mxa = a[0];
    for (int i = 1; i < n; i++) {
      ans = max(ans, mxa - a[i]);
      mxa = max(mxa, a[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
