#include <iostream>
using namespace std;
int x[30];
int main()
{
  int n;
  cin >> n;
  while (n--) {
    int cnt = 0;
    for (int i = 0; i < 26; i++) {
      int a;
      cin >> a;
      x[a]++;
      cnt++;
    }
    for (int 0; i < cnt; i++) {
      for (int j = 26; j >= 1; j--) {
        if (x[j] >= 0) {
          
        }
      }
    }
  }
  return 0;
}
