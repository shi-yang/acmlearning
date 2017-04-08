#include <bits/stdc++.h>
using namespace std;
int main()
{
  //freopen("data.in", "r", stdin);
  string s1, s2;
  cin >> s1 >> s2;
  int n;
  cin >> n;
  cout << s1 << ' ' << s2 << endl;
  for (int i = 0; i < n; i++) {
    string str1, str2;
    cin >> str1 >> str2;
    if (str1 == s1) {
      s1 = str2;
    } else {
      s1 = s1;
      s2 = str2;
    }
    cout << s1 << ' ' << s2 << endl;
  }
  return 0;
}
