#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
  int a, b;
  while (scanf("%lld%d", &a, &b) != EOF) {
    if (!a && !b)
      break;
    a *= 100;
    int f = 0;
    for (int i = 0; i <= 99; i++) {
      if ((a + i) % b == 0) {
        if (f)
          printf(" ");
        f = 1;
        if (i / 10 == 0) {
          printf("0%d", i);
        } else {
          printf("%d", i);
        }
      }
    }
    cout << endl;
  }
  return 0;
}
