#include <iostream>
#include <cstdio>
using namespace std;
int getsum(int num, int x)
{
  int sum = 0;
  while (num) {
    sum += (num % x);
    num /= x;
  }
  return sum;
}
int main()
{
  int n;
  while (scanf("%d", &n) && n) {
    if (getsum(n, 10) == getsum(n, 16) && getsum(n, 10) == getsum(n, 12)) {
      cout << n << " is a Sky Number." << endl;
    } else {
      cout << n << " is not a Sky Number." << endl;
    }
  }
  return 0;
}
