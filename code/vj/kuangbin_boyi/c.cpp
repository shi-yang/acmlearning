#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
  int n;
  while (~scanf("%d", &n) && n) {
    if (n & 1) {
      cout << "ailyanlu" << endl;
    } else {
      cout << "8600" << endl;
    }
  }
  return 0;
}