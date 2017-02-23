#include <iostream>
using namespace std;
int a[21];
int main()
{
  a[0] = 0;
  a[1] = 2;
  for (int i = 2; i <= 21; i++) {
    a[i] = a[i - 1] * 3 + 2;
  }
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << a[n - 1] + 2 << endl;
  }
  return 0;
}
