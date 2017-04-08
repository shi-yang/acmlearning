#include <bits/stdc++.h>
using namespace std;
const int maxn = 300005;
int a[maxn], b[maxn];
map<int, int> mp;
map<int, int> same;
struct edge {
  int id, v;
} before[maxn], after[maxn];
int main()
{
  int n;
  scanf("%d", &n);
  long long sum = 0, tmp = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &before[i].v);
    before[i].id = 0;
  }
  sort(before, before + n);
  after[0] = before[0].v;
  for (int i = 1; i < n; i++) {
    if (before[i] == before[i - 1]) {

    } else {
      after[i]
    }
  }
  for (int i = 0; i < n; i++) {
    if (i)
      printf(" ");
    printf("%d", b[i]);
  }
  printf("\n");
  return 0;
}
