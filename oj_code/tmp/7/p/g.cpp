#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 201;
struct edge {
  int to;
  string str;
};
vector<edge> G[maxn];
void dfs(int a, int b)
{
  if (a == b) {
    return;
  } else {
    for (int i = 0; i < G[a].size(); i++) {
      edge v = G[a][i];
      
    }
  }
}
int main()
{
  int n;
  while (~scanf("%d", &n) && n) {
    int a, b;
    for (int i = 1; i <= n; i++)
      G[i].clear();
    while (~scanf("%d %d", &a, &b) && (a + b)) {
      string str;
      cin >> str;
      G[a].push_back((edge){b, string});
    }
    while (~scanf("%d %d", &a, &b) && (a + b)) {
      dfs(a, b);
    }
  }
  return 0;
}
