#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main()
{
  int t;
  scanf("%d", &t);
  int kas = 1;
  while (t--) {
    string name[6][20];
    map<string, int> mp;
    int g;
    string str;
    cin >> g >> str;
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 20; j++) {
        cin >> name[i][j];
      }
    }
    int x = 0, y = 0;
    int f = 0;
    for (int j = 0; j < 20; j++) {
      for (int i = 0; i < 5; i++) {
        if (name[i][j] == str) {
            f = 1;
            break;
        }
        if (mp[name[i][j]])
          continue;
        mp[name[i][j]]++;
        x++;
      }
      if (f)
        break;
    }
    for (int i = 0; i < 20; i++) {
      if (name[5][i] == str)
        break;
      if (mp[name[5][i]])
        continue;
      y++;
    }
    if (x + y <= g) {
      printf("Case #%d: ADVANCED!\n", kas++);
      continue;
    }
    int ans = min(g - x, y);
    if (ans < 0)
      ans = 0;
    printf("Case #%d: %d\n", kas++, ans);
  }
  return 0;
}
