```C++
const int INF = 100000000;
typedef pair<int, int> P;

char maze[MAX_N][MAX_M + 1];
int N, M;
int sx, sy;
int gx, gy;

int d[MAX_N][MAX_M];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int bfs()
{
  queue<P> que;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      d[i][j] = INF;
      
}
```
