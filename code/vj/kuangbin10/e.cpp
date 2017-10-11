#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 105;
int mp[N][N], n;
int link[N], vis[N];
int dfs(int u)
{
  for (int i = 0; i < n; i++) {
    if (mp[u][i] && !vis[i]) {
      vis[i] = 1;
      if (link[i] == -1 || dfs(link[i])) {
        link[i] = u;
        return 1;
      }
    }
  }
  return 0;
}
int main()
{
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        scanf("%d", &mp[i][j]);
      }
    }
    memset(link, -1, sizeof(link));
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      memset(vis, 0, sizeof(vis));
      cnt += dfs(i);
    }
    if (cnt != n) {
      puts("-1");
      continue;
    }
    vector<pair<int, int> > ans;
    for (int i = 0; i < n; i++) {
      int k = 0;
      while (link[k] != i)
        k++;
      if (k != i) {
        ans.push_back(make_pair(i + 1, k + 1));
        swap(link[i], link[k]);
      }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) {
      printf("C %d %d\n", ans[i].first, ans[i].second);
    }
  }
  return 0;
}