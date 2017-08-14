#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 80;
char m[maxn][maxn];
int main()
{
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  int n;
  char s1, s2;
  bool tt = false;
  while (cin >> n >> s1 >> s2) {
    if (tt)
      cout << endl;
    tt = true;
    if (n == 1) {
      cout << s1 << endl;
      continue;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        m[i][j] = ' ';
      }
    }
    int cnt = n * n;
    int x, y;
    bool flag;
    char str;
    if (((n + 1) >> 1) % 2) {
      flag = true;
    } else {
      flag = false;
    }
    m[x = 0][y = 0] = s1;
    while (cnt--) {
      if (flag) {
        str = s1;
      } else {
        str = s2;
      }
      while (x + 1 < n && m[x + 1][y] == ' ')
        m[++x][y] = str;
      while (y + 1 < n && m[x][y + 1] == ' ')
        m[x][++y] = str;
      while (x - 1 >= 0 && m[x - 1][y] == ' ')
        m[--x][y] = str;
      while (y - 1 >= 0 && m[x][y - 1] == ' ')
        m[x][--y] = str;
      flag = (flag) ? false : true;
    }
    m[0][0] = m[n - 1][0] = m[0][n - 1] = m[n - 1][n - 1] = ' ';
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        printf("%c", m[i][j]);
      }
      cout << endl;
    }
  }
  return 0;
}
