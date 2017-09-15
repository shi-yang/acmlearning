#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n, p, q;
  while (~scanf("%d %d %d", &n, &p, &q)) {
    int c = n % (p + q);
    // n = (p + q) * r + c;
    if (c == 0 || c > p) {
      puts("WIN");
    } else {
      puts("LOST");
    }
  }  
  return 0;
}