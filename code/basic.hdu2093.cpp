#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
struct edge {
  char name[11];
  int ac;
  int cost;
} e[20];
bool cmp(edge a, edge b)
{
  if (a.ac != b.ac) {
    return a.ac > b.ac;
  } else {
    return a.cost < b.cost;
  }
}
int main()
{
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  int cnt = 0;
  while (cin >> e[cnt].name) {
    int acnum = 0;
    int cost = 0;
    for (int i = 0; i < n; i++) {
      string str;
      cin >> str;
      if (str[0] != '0' && str[0] != '-') {
        acnum++;
        int lc = 0, t = 0;
        while (str[lc] != '(' && lc < str.size()) {
          t = t * 10 + str[lc] - '0';
          lc++;
        }
        //cout << "cnt " << cnt << " t " << t << endl;
        cost += t;
        if (lc < str.size() && str[lc] == '(') {
          t = 0;
          int rc = lc + 1;
          while (str[rc] != ')' && rc < str.size()) {
            t = t * 10 + str[rc] - '0';
            rc++;
          }
          cost += (t * m);
        }
      }
    }
    e[cnt].ac = acnum;
    e[cnt].cost = cost;
    cnt++;
  }
  sort(e, e + cnt, cmp);
  for (int i = 0; i < cnt; i++) {
    printf("%-10s %2d %4d\n", e[i].name, e[i].ac, e[i].cost);
  }
  return 0;
}
