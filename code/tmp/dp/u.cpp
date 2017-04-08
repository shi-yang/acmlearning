#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int m[1000][1000];
int main()
{
  string s1, s2;
  freopen("data.in", "r", stdin);
  while (cin >> s1 >> s2) {
    memset(m, 0, sizeof(m));
    for (int i = 0; i < s1.size(); i++) {
      for (int j = 0; j < s2.size(); j++) {
        if (s1[i] == s2[j]) {
          m[i + 1][j + 1] = m[i][j] + 1;
        } else {
          m[i + 1][j + 1] = max(m[i + 1][j], m[i][j + 1]);
        }
      }
    }
    cout << m[s1.size()][s2.size()] << endl;
  }
  return 0;
}
