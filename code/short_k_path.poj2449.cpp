#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
struct edge {
  int u, v, t;
}e[maxn];
int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].t);
  }
  int s, t, k;
  scanf("%d %d %d", &s, &t, &k);
  return 0;
}