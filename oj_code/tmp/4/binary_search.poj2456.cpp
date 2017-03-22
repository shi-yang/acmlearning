#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100005;
int a[maxn];
int n, c;
int dis(int m) {
  int s = 0, cnt = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] - a[s] >= m) {
      cnt++;
      s = i;
    }
  }
  return cnt + 1 >= c;
}
int main()
{
  cin >> n >> c;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);
  int l = 0, r = 1e9;
  while (r - l > 1) {
    int m = (l + r) >> 1;
    if (dis(m)) {
      l = m;
    } else {
      r = m;
    }
  }
  cout << l << endl;
  return 0;
}
