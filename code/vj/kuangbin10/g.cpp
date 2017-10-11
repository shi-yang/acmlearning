#include <iostream>
#include <cstdio>
using namespace std;
const int N = 666;
char mp[N][N];
int main()
{
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    
    
    g[1][4] = 1;
    g[2][5] = 1;
    
    memset(link, -1, sizeof(link));
    for (int i = 0; i < 5; i++) {
      memset(vis, 0, sizeof(vis));
      ans += dfs(i);
    }
    //ans = 2;
    
    
  }
  return 0;
}