#include <bits/stdc++.h>
using namespace std;
bool leap(int y)
{
  if (y % 400 == 0 || y % 4 == 0 && y % 100 != 0)
    return true;
  return false;
}
int main()
{
  int t;
  scanf("%d", &t);
  while (t--) {
    int y, yy, m, mm, d, dd;
    scanf("%d %d %d %d %d %d %d %d", &y, &m, &d, &yy, &mm, &dd);
    int ye = y;
    while (ye != yy) {
      
    }
  }
  return 0;
}