#include <iostream>
using namespace std;
const int maxn = 12;
char maze[maxn][maxn][2];
bool vis[maxn][maxn][2];
int tx[4] = {0, 0, -1, 1};
int ty[4] = {-1, 1, 0, 0};
int n, m, t;
void bfs()
{
  memset(vis, 0, sizeof(vis));
  
}
int main()
{
  int cc;
  cin >> cc;
  while (cc--) {
    cin >> n >> m >> t;
    for (int k = 0; k < 2; k++) {
      for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
          maze[i][j][k] = s[j];
        }
      }
    }
    bfs();
  }
  return 0;
}
