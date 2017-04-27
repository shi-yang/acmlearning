#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
  int n;
  cin >> n;
  int mx = -1e5;
  int miz = 1e5;
  int zsum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > 0)
      zsum += a[i];
    if (a[i] & 1) {
      miz = min(miz, abs(a[i]));
      mx = max(mx, a[i]);
    }
  }
  int ans;
  if (zsum > 0) {
    if (zsum & 1) {
      ans = zsum;
    } else {
      ans = zsum - miz;
    }
  } else {
    ans = mx;
  }  
  cout << ans << endl;
  return 0;
}