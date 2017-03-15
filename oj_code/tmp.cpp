#include <bits/stdc++.h>
using namespace std;
const int maxn = 101;
int n, m;
int mp[maxn][maxn];
int main()
{
  while (cin >> n >> m && n && m) {
    memset(mp, 0, sizeof(mp));
    for (int i = 1; i <= n; i++) {
      string str;
      cin >> str;
      for (int j = 0; j < str.size(); j++) {
        if (str[j] == 'H') {
          mp[0][j] = 1;
        } else if (str[j] == 'm') {
          mp[]
        } else {

        }
      }
    }

  }
	return 0;
}
