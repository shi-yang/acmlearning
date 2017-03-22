#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  long long  mx = -1;
  for (int i = 0; i < n; i++) {
    long long  x;
    cin >> x;
    mx = max(mx, x);
  }
  if ((mx - n) % 2 != 0) {
    cout << "Alice" << endl;
  } else {
    cout << "Bob" << endl;
  }
  return 0;
}
