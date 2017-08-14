#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while (t--) {
    int h, m, s;
    cin >> h >> m >> s;
    if (h >= 12)
      h -= 12;
    float t1 = 30.0 * h + (m + s / 60.0) / 2.0;
    float t2 = 6.0 * (m + s / 60.0);
    float t3 = fabs(t1 - t2);
    if (t3 > 180)
      t3 = 360 - t3;
    t3 = (int)t3;
    cout << t3 << endl;
  }
  return 0;
}
