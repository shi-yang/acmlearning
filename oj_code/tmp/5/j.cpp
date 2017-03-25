#include <iostream>
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int m[5][5];
int sx, sy;
string path;
bool check()
{
  int cnt = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i == 3 && j == 3) {
        continue;
      }
      if (m[i][j] != ++cnt) {
        return false;
      }  
    }
  }
  return true;
}
void dfs(int x, int y)
{
  if (
  for (int i = 0; i < 4; i++) {
    int nx = dx[i], ny = dy[i];
  }
}
int main()
{
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      char s;
      cin >> s;
      m[i][j] = s;
      if (s == 'X')
        sx = i, sy = j;
    }
  }
  dfs(sx, sy);   
  return 0;
}