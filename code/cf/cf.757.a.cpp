#include <bits/stdc++.h>
using namespace std;
string str = "Bulbasaur";
map<char, int> cnt;
int main()
{
  string s;
  cin >> s;
  for (int i = 0; i < 57; i++) {
    char c = 'A' + i;
    cnt[c] = 0;
  }
  for (int i = 0; i < s.length(); i++) {
    cnt[s[i]]++;
  }
  cnt['a'] >>= 1;
  cnt['u'] >>= 1;
  int ans = 999999;
  for (int i = 0; i < str.length(); i++) {
    ans = min(ans, cnt[str[i]]);
  }
  cout << ans << endl;
  return 0;
}
