#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
void merge(int a[], int p, int q, int r)
{
  int i = p, j = q + 1, k = 0;
  while (i <= q && j <= r) {
    if (a[i] <= a[j]) {
      tmp[k++] = a[i++];
    } else {
      tmp[k++] = a[j++];
    }
  }
  while (i <= q)
    tmp[k++] = a[i++];
  while (j <= r)
    tmp[k++] = a[j++];
  for (int c = 0; c < k; c++)
    a[p + c] = tmp[c];
}

void merge_sort(int a[], int p, int r)
{
  if (p < r) {
    int q = (p + r) / 2;
    merge_sort(a, p, q);
    merge_sort(a, q + 1, r);
    merge(a, p, q, r);
  }
}

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  return 0;
}
