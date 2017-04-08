#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int sum = 0;
    int mi = 999;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      sum += x;
      mi = min(x, mi);
    }
    cout << sum - mi << endl;
  }
  return 0;
}
