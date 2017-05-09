#include <bits/stdc++.h>
using namespace std;
const int md = 1e9+7;
int main()
{
  string str;
  cin >> str;
  int len = str.size();
  long long bcnt = 0;
  long long ans = 0;
  for (int i = len - 1; i >= 0; i--) {
    if (str[i] == 'a') {
      ans += bcnt;
      bcnt %= md;
      bcnt *= 2;
      bcnt %= md;
    } else {
      bcnt++;
      bcnt %= md;
    }
  }
  cout << ans % md << endl;
  return 0;
}
