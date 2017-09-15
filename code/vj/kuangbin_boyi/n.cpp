#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    if (n % (m + 1)) {
      puts("Grass");
    } else {
      puts("Rabbit");
    }
  }
  return 0;
}