#include <iostream>
#include <cstdio>
using namespace std;
const int N = 20;
int g[N][N];
int main()
{
  int n, m;
  while (~scanf("%d %d", &n, &m)) {
    for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      g[a][b] = g[b][a] = 1;
    }
    
  }
  return 0;
}