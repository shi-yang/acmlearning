#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int a[maxn], b[maxn];
int main()
{
    int sum_a = 0, sum_b = 0;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &a[i], &b[i]);
      sum_a += a[i];
      sum_b += b[i];
    }
    int ans = abs(sum_a - sum_b);
    int l = 0;
    for (int i = 0; i < n; i++) {
      int tmp = abs((sum_a - a[i] + b[i]) - (sum_b - b[i] + a[i]));
      if (ans < tmp) {
        ans = tmp;
        l = i + 1;
      }
    }
    cout << l << endl;
    return 0;
}
