#include <iostream>
#include <cstdio>
using namespace std;
__int64 v[55];
void f()
{
  v[0] = 0;
  v[1] = 1;
  for (int i = 2; i < 55; i++) {
    v[i] = v[i - 1] + v[i - 2];
  }
}
int main()
{
  int n;
  f();
  while (scanf("%d", &n) && n != -1) {
    printf("%I64d\n", v[n]);
  }
  return 0;
}
