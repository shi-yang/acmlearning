#include <iostream>
using namespace std;
int main()
{
  int n;
  while (scanf("%d", &n) && n) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int a;
      scanf("%d", &a);
      ans ^= a;
    }
    printf("%d\n", ans);
  }
  return 0;
}
