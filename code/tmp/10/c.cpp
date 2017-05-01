#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
  string str;
  int m;
  while (cin >> str >> m) {
    int cnt = str.size() - m;
    string ans;
    int pos = 0;
    while (cnt--) {
      for (int i = pos + 1; i <= m; i++) {
        if (str[pos] > str[i])
          pos = i;
      }
      ans += str[pos++];
      m++;
    }
    int k = 0;
    while (ans[k] == '0') k++;
    if (k == ans.size())
      ans = '0';
    else
      ans = ans.substr(k, ans.size() - k);
    cout << ans << endl;
  }
  return 0;
}