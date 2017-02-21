#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s1, s2;
    cin >> s1 >> s2;
    int t1 = s1[s1.size() - 1] - '0' + s2[s2.size() - 1] - '0';
    int t2, t3;
    if (s1.size() == 1) {
      t2 =  0;
    } else {
      t2 = s1[s1.size() - 2] - '0';
    }
    if (s2.size() == 1) {
      t3 = 0;
    } else {
      t3 = s2[s2.size() - 2] - '0';
    }
    int t = t3 + t2;
    t %= 10;
    t *= 10;
    cout << (t1 + t) % 100 << endl;
  }
  return 0;
}
