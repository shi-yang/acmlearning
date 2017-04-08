/*
  第一次写并查集时的代码，用的是　coursera.org 上的算法教程上的代码模板。
  现在看，在查找根节点时还是可以路径压缩的，直接写成
  int root(int x)
  {
      return x == f[x] ? x : f[x] = root(f[x]);
  }
  会高效得多。
 */
#include <cstdio>
#include <algorithm>
using namespace std;
int f[105], n, m;
struct edge
{
    int from, to, cost;
} t[5500];
int cmp(edge x, edge y)
{
    return x.cost < y.cost;
}
int root(int x)
{
    while (x != f[x])
        x = f[x];
    return x;
}
bool connected(int x, int y)
{
    return root(x) == root(y);
}
int Kruskal()
{
    int ans = 0;
    sort(t, t + n, cmp);
    for (int i = 0; i < n; i++) {
        if (connected(t[i].from, t[i].to))
            continue;
        f[root(t[i].from)] = root(t[i].to);
        ans += t[i].cost;
    }
    return ans;
}
int main()
{
    int s;
    while(scanf("%d%d", &n, &m) != EOF){
        if(n == 0)
            break;
        for (int i = 0;i < n; i++)
            scanf("%d%d%d",&t[i].from, &t[i].to, &t[i].cost);
        for (int i = 0;i <= m; i++)
            f[i] = i;
        s = Kruskal();
        for (int i = 2; i <= m; i++)
            if (!connected(i, 1))
                s = -1;
        if(s==-1)
            printf("?\n");
        else
            printf("%d\n", s);
    }
    return 0;
}
