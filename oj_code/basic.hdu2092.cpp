#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  int n, m;
  while (~scanf("%d%d", &n, &m)) {
    if (!n && !m)
      break;
    int des = n * n - 4 * m;
    if (des < 0) {
      cout << "No" << endl;
      continue;
    }
    double x = (n + sqrt(des)) / 2;
    double y = (n - sqrt(des)) / 2;
    if (x == (int)x && y == (int)y) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
