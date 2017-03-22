#include <iostream>
using namespace std;
typedef long long ll;
void merge(ll n, int l, int r)
{
  if (l < l) {
    int m = (l + r) / 2;
    if (n % 2 != 0) {
      merge(n >> 1, l, m);
      merge(1, l, m + 1);
      merge(n >> 1, m + 2, r);
    } else {
      merge(n >> 1, l, m);
      merge(n >> 1, m + 1, r);
    }
  }

}
int main()
{
  int n, l, r;
  cin >> n >> l >> r;
  merge(n, 0, n - 1);
  return 0;
}
