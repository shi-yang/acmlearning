#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--) {
    int ans = 0;
    int n;
    cin >> n;
    while (n--) {
      int x;
      cin >> x;
      if (x > 6000)
        ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
