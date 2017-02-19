#include <stdio.h>
#define MAXN 1000
int tmp[MAXN];
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

void insert_sort(int a[], int n)
{
  for (int i = 1; i < n; i++) {
    int key = a[i];
    int j = i - 1;
    while (key < a[j] && j >= 0) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = key;
  }
}

int main()
{
  int a[10] = {1, 6, 4, 8, 3, 2, 0, 10, 9, 5};
  merge_sort(a, 0, 9);
  for (int i = 0; i < 10; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}
