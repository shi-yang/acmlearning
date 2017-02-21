#include <iostream>
#include <cstring>
using namespace std;
struct edge {
  string name;
  int cnt[30];
} e[20];
int main()
{
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> e[i].name;
    for (int j = 0; j < m; j++) {
      cin >> e[i].cnt[j];
    }
  }
  return 0;
}
