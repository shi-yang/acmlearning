#include <bits/stdc++.h>
using namespace std;
int n, x[1005];
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &x[i]);
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < n; j++) {
      if ((x[i] < x[j] && x[j] < x[i + 1] && x[j + 1] > x[i + 1])) {
        printf("yes\n");
        return 0;
      }
    }
  }
  printf("no\n");
  return 0;
}
