#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
map<string, bool> mp;
int main()
{
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    string str;
    while (getline(cin, str)) {
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
          if (!mp[s]) {
            mp[s] = 1;
            ans++;
          }
          cnt = 0;
        }
      }
      cout << ans << endl;
    }
    return 0;
}
