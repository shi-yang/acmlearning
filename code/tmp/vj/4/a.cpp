#include <bits/stdc++.h>
using namespace std;
int a[105], b[105];
int main()
{
  int n;
  cin >> n;
  int suma = 0, sumb = 0;
  int cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    suma += a[i], sumb += b[i];
    if ((a[i] & 1) && (b[i] & 1)) {
      cnt1++;
    } else if ((a[i] & 1) || (b[i] & 1)) {
      cnt2++;
    }
  }
  int ans;
  if (!(suma & 1) && !(sumb & 1)) {
    ans = 0;
  } else if ((suma + sumb) & 1) {
    ans = -1;
  } else {
    if (((cnt1 & 1) && cnt2 % 2 == 0) && cnt2 == 0)
      ans = -1;
    else
      ans = 1;
  }
  cout << ans << endl;
  return 0;
}
