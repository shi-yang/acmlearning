#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int N = 105;
struct edge {
  int to, co;
  edge(){}
  edge(int to, int co) : to(to), co(co) {}
};
int inq[N];
vector<edge> G[N];
void spfa()
{

}
int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= i - 1; j++) {
      char str[10];
      int x;
      scanf("%s", str);
      if (str[0] != 'x') {
        sscanf(str, "%d", &x);
        G[i].push_back(edge(j, x));
        G[j].push_back(edge(i, x));
      }
    }
  }
  spfa();
  return 0;
}