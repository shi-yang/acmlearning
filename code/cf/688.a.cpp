#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n, d;
  scanf("%d %d", &n, &d);
  int ans = 0, cnt = 0;
  for (int i = 0; i < d; i++) {
    string str;
    cin >> str;
    int ok = 0;
    for (int j = 0; j < str.size(); j++)
      if (str[j] == '0') {
        cnt++;
        ok = 1;
        break;
      }
    if (!ok)
      cnt = 0;
    ans = max(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}
