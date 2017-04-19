#include <iostream>
#include <cstdio>
using namespace std;
const int N = 100005;
int a[N];
int main()
{
  int n, t;
  int kase = 1;
  scanf("%d" ,&t);
  while (t--) {
    scanf("%d", &n);
    int l, r;
    int sum = -1e9;
    int mx = -1e9;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }    
    int tmp;
    for (int i = 0; i < n; i++) {
      int t = a[i];
      if (sum + t < t) {
        sum = t, tmp = i;
      } else {
        sum += t;
      }
      if (sum > mx) {
        mx = sum;
        l = tmp;
        r = i;
      }
    }
    printf("Case %d:\n%d %d %d\n", kase++, mx, l, r);
  }
  return 0;
}