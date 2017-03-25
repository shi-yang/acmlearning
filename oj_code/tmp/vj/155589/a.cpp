#include <bits/stdc++.h>
using namespace std;
int main()
{
  int k, d;
  cin >> k >> d;
  if (d == 0 && k > 1)
    cout << "No solution";
  else {
    cout << d;
    while (--k) {
      cout << 0;
    }
  }
  cout << endl;
  return 0;
}