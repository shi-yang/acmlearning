#include <iostream>
#include <map>
using namespace std;
int main()
{
  int n;
  while (scanf("%d", &n) && n) {
    map<string, int> mp;
    string str1, str2;
    for (int i = 0; i < n; i++) {
      cin >> str1 >> str2;
      if (mp[str1] != -1)
        mp[str1] = 0;
      mp[str2] = -1;
    }
    int cnt = 0;
    map<string, int>::iterator it;
    it = mp.begin();
    while (it != mp.end()) {
      if (it->second != -1) {
        cnt++;
      }
      it++;
    }
    if (cnt == 1) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
