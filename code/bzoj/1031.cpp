#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
char s[N];
struct node {
  char c, b;
  bool operator < (const node &a) const {
    return c < a.c;
  }
} n[N];
int main()
{
  scanf("%s", s);
  int len = strlen(s);
  n[0].c = s[0], n[0].b = s[len - 1];
  for (int i = 1; i < len; i++) {
    n[i].c = s[i];
    n[i].b = s[i - 1];
  }
  sort(n, n + len);
  for (int i = 0; i < len; i++) {
    printf("%c", n[i].b);
  }
  puts("");
  return 0;
}