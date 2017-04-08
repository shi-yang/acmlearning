#include <bits/stdc++.h>
using namespace std;
int main()
{
  int r, x, y, xx, yy;
  scanf("%d %d %d %d %d", &r, &x, &y, &xx, &yy);
  double dis = sqrt(double(x - xx) * (x - xx) + double(y - yy) * (y - yy));
  int ans = ceil(dis / (2.0 * r));
  printf("%d\n", ans);
  return 0;
}
