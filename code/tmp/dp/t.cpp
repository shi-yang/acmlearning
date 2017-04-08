#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 10005;
int a[maxn];
int ans;
int que[maxn];
void dp(int k)
{
  int min = 1e9, flag, tmin = 1e9, tflag;
  for (int i = 1; i < k; i++) {
    int kcnt = 0;
    for (int j = 1; j <= ans; j++) {
      if (a[i] > que[j]) {
        kcnt++;
        if (a[i] - que[j] < min) {
          min = a[i] - que[j];
          flag = j;
        }
      }
      if (a[i] - que[j] < tmin) {
        tmin = a[i] - que[j];
        tflag = j;
      }
    }
    if (kcnt == ans) {
      que[++ans] = a[i];
    } else if (kcnt > 0) {
      que[flag] = a[i];
    } else {
      que[tflag] = a[i];
    }
  }
}
int main()
{
  int k;
  //freopen("data.in", "r", stdin);
  while (scanf("%d", &k) && k) {
    for (int i = 0; i < k; i++)
      cin >> a[i];
    ans = 1;
    memset(que, 0, sizeof(que));
    que[1] = a[0];
    dp(k);
    cout << ans << endl;
  }
  return 0;
}
