#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int m[1000][1000];
int main()
{
  string s1, s2;
  cin >> s1 >> s2;
  memset(m, 0, sizeof(m));
  for (int i = 0; i < s1.size(); i++) {
    for (int j = 0; j < s2.size(); j++) {
      if (s1[i] == s2[j]) {
        if (i != 0 && j != 0) {
          m[i][j] = m[i - 1][j - 1] + 1;
        } else {
          m[i][j] = 1;
        }
      } else {
        if (i != 0 && j != 0)
          m[i][j] = max(m[i - 1][j], m[j - 1][i]);
      }
    }
  }
  cout << m[s1.size() - 1][s2.size() - 1] << endl;
  return 0;
}
