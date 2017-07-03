#include <cstdio>
#include <map>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int n = 8;
const int m = 24 + 9;
char maze[10][50];
struct node {
  char key;
  char col;
  int row;
} e[60], P[20], p[20];
bool cmp_white(node a, node b)
{
  if (a.row != b.row)
    return a.row < b.row;
  return a.col < b.col;
}
bool cmp_black(node a, node b)
{
  if (a.row != b.row)
    return a.row > b.row;
  return a.col < b.col;
}
map<char, int> mp;
map<char, bool> chess;
char piece[] = "KQRBNPkqrbnp";
int num = 0;
int vis[50];
char cap[][20] = {"White", "Black"};
void print(int &cnt, int n, int t)
{
  printf("%s: ", cap[t]);
  if (t == 0) {
    sort(e, e + num, cmp_white);
  } else {
    sort(e, e + num, cmp_black);
  }
  bool flag;
  memset(vis, 0, sizeof(vis));
  for (int i = 0; cnt < n; flag ? i++ : cnt++) {
    flag = false;
    for (int j = 0; j < num; j++) {
      if (e[j].key == piece[cnt] && !vis[j]) {
        if (i)
          printf(",");
        if (piece[cnt] == 'P' || piece[cnt] == 'p') {
          printf("%c%d", e[j].col, e[j].row);
        } else {
          printf("%c%c%d", toupper(e[j].key), e[j].col, e[j].row);
        }
        vis[j] = 1;
        flag = true;
        break;
      }
    }
  }
  printf("\n");
}
int main()
{
  int len = strlen(piece);
  for (int i = 0; i < len; i++) {
    mp[piece[i]] = i;
    chess[piece[i]] = true;
  }
  for (int i = 0; i < n; i++) {
    scanf("%*s%s", maze[i]);
    for (int j = 0; j < m; j++) {
      char col = 'a' + (j + 2) / 4 - 1;
      int row = n - i;
      if (chess[maze[i][j]]) {
        e[num].key = maze[i][j];
        e[num].col = col;
        e[num++].row = row;
      }
    }
  }
  scanf("%*s");
  int tmp = 0;
  print(tmp, len / 2, 0);
  print(tmp, len, 1);
  return 0;
}