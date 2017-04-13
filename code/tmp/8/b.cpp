#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int a[maxn];
int main()
{
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if ((a[i] ^ a[j]) > max(a[i], a[j])) {
          ans++;
          int t = a[i] ^ a[j];
          cout << a[i] << ' ' << a[j] << ' ' << t << endl;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
