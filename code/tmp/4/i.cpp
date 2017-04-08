#include <iostream>
#include <cmath>
using namespace std;
int n, k;
int a[100005];
bool c(int m)
{
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > m) {
      //printf("%.20lf\n", (a[i] - m) * 1.0 / (k - 1));
      sum += (a[i] - m + k - 2) / (k - 1);
      if(sum > m)
        return false;
    }
  }
  return true;
}
int main()
{
  //freopen("in", "r", stdin);
  cin >> n;
  int maxa = -1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    maxa = max(maxa, a[i]);
  }
  cin >> k;
  if (k == 1) {
    cout << maxa << endl;
    return 0;
  }
  int l = 0, r = 1e9;
  while (r > l) {
    int m = (r + l) >> 1;
    c(m) ? r = m : l = m + 1;
    //cout << l << ' ' << r << endl;
  }
  cout << r << endl;
  return 0;
}
