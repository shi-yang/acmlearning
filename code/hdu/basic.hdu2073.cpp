#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn = 101;
double dis[maxn << 1][maxn << 1];
void getdis()
{
  memset(dis, 0, sizeof(dis));
  int cnt = 2;
  double tmp = sqrt(2.0);
  dis[0][0] = 0;
  dis[0][1] = 1;
  dis[1][0] = 1.0 + tmp;
  while (cnt < (maxn << 1)) {
    int x = 0, y = cnt;
    while (x + y == cnt && y >= 0) {
      double dist;
      if (x == 0) {
        dist = sqrt((y * y) + (y - 1) * (y - 1));
        dis[x][y] = dis[y - 1][x] + dist;
      } else {
        dis[x][y] = dis[x - 1][y + 1] + tmp;
      }
      x++;
      y--;
    }
    cnt++;
  }
}
int main()
{
  int n;
  //freopen("data.in", "r", stdin);
  getdis();
  cin >> n;
  while (n--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double t1 = dis[x1][y1];
    double t2 = dis[x2][y2];
    printf("%.3lf\n", fabs(t1 - t2));
  }
  return 0;
}
