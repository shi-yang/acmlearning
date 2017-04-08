#include <bits/stdc++.h>
using namespace std;
int a[100005];
bool cmp(int a, int b) {
  return a > b;
}
int main()
{
  int n, n1, n2;
  scanf("%d%d%d", &n, &n1, &n2);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  sort(a, a + n, cmp);
  if (n1 > n2)
    swap(n1, n2);
  long long sum1 = 0, sum2 = 0;
  for (int i = 0; i < n1; i++)
    sum1 += a[i];
  for (int i = 0; i < n2; i++)
    sum2 += a[i + n1];
  printf("%.8lf\n", 1.0 * sum1 / n1 + 1.0 * sum2 / n2);
	return 0;
}
