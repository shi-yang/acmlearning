#include <bits/stdc++.h>
using namespace std;
const int N = 25005;
struct node {
  char name[20];
  int len;
} e[N];
int dp[N];
int main()
{
  int n = 0;
  while (~scanf("%s", e[n].name)) {
    e[n].len = strlen(e[n].name);
    n++;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      int leni = e[i].len, lenj = e[j].len;
      if (leni == lenj) {
        int cnt = 0;
        for (int k = 0; k < leni; k++) {
          if (e[i].name[k] != e[j].name[k]) {
            cnt++;
          }
        }
        if (cnt == 1) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      } else if (leni == lenj + 1) {
        int cnt = 0;
        for (int l = 0, r = 0; l < leni; l++, r++) {
          if (e[i].name[l] != e[j].name[r]) {
            r--;
            cnt++;
          }
        }
        if (cnt == 1) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      } else if (lenj == leni + 1) {
        int cnt = 0;
        for (int l = 0, r = 0; l < lenj; l++, r++) {
          if (e[j].name[l] != e[i].name[r]) {
            r--;
            cnt++;
          }
        }
        if (cnt == 1) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }
    ans = max(ans, dp[i]);
  } 
  printf("%d\n", ans);
  return 0;
}