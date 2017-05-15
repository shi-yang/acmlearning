#include <bits/stdc++.h>
using namespace std;
int main()
{
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  int n;
  scanf("%d", &n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    if (x > b && x < c) {
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}