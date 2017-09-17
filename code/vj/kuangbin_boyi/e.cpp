#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
  int n;
  while (cin >> n) {
    printf("%s\n", n % 3 ? "Kiki" : "Cici");
  }
  return 0;
}