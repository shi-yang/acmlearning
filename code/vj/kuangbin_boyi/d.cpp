#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    int c = n % (m + 1);
    if (c) {
      cout << "first" << endl;
    } else {
      cout << "second" << endl;
    }
  }
  return 0;
}