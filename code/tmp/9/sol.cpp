#include <bits/stdc++.h>
using namespace std;
int main()
{
  for (int i = 100; i < 500; i++) {
    int a = rand() % i, b = a * i;
    if (a == 0 || b == 0)
      continue;
    printf("%d %d\n", a, b);
  }
  return 0;
}