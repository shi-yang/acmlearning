#include <bits/stdc++.h>
using namespace std;
int reg[15];
string in[1005];
int solve(int n)
{
  int cnt = 1, cur = 0;
  for (;;) {
    int c = in[cur][0] - '0';
    int d = in[cur][1] - '0';
    int n = in[cur][2] - '0';
    cur++;
    if (c == 1) {
      if (!d && !n)
        break;
    } else if (c == 2) {
      reg[d] = n;
    } else if (c == 3) {
      reg[d] = (reg[d] + n) % 1000;
    } else if (c == 4) {
      reg[d] = (reg[d] * n) % 1000;
    } else if (c == 5) {
      reg[d] = reg[n];
    } else if (c == 6) {
      reg[d] = (reg[d] + reg[n]) % 1000;
    } else if (c == 7) {
      reg[d] = (reg[d] * reg[n]) % 1000;
    } else if (c == 8) {
      stringstream ss;
      ss << in[reg[n]];
      ss >> reg[d];
    } else if (c == 9) {
      stringstream ss;
      ss << reg[d];
      ss >> in[reg[n]];
    } else if (c == 0) {
      if (reg[n]) {
        cur = reg[d];
      }
    }
    cnt++;
  }
  return cnt;
}
int main()
{
  int t;
  scanf("%d", &t);
  getchar();
  while (t--) {
    int n = 0;
    getchar();
    while (getline(cin, in[n]) && in[n] != "") {
      n++;
    }
    printf("%d\n", solve(n));
    if (t)
      puts("");
  }
  return 0;
}