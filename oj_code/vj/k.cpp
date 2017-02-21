#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int main()
{
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    string str;
    while (getline(cin, str)) {
      map<string, bool> mp;
      if (str[0] == '#')
        break;
      str += ' ';
      int cnt = 0;
      int ans = 0;
      for (int i = 0; i < str.size(); i++) {
        if ('a' <= str[i] && str[i] <= 'z') {
          cnt++;
        } else {
          string s = str.substr(i - cnt, cnt);
          if (s == "")
            continue;
          if (mp[s] == false) {
            mp[s] = true;
            ans++;
          }
          cnt = 0;
        }
      }
      cout << ans << endl;
    }
    return 0;
}
