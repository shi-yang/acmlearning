#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 8006;
struct edge {
  int l, r, c;
}e[maxn];
int main()
{
  int n;
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n; i++) {
      scanf("%d %d %d", &e[i].l, &e[i].r, &e[i].c); 
    }
  }
  return 0;
}