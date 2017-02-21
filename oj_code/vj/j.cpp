#include <iostream>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    float a, ans = -1;
    for (int i = 0; i < n; i++) {
      cin >> a;
      ans = max(ans, a);
    }
    printf("%.2f\n", ans);
  }
  return 0;
}
