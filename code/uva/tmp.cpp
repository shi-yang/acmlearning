#include <bits/stdc++.h>
using namespace std;
int tmp[1000];
int ans;
void merge(int *a, int l, int r)
{
    if (l == r) {
        return;
    }
    int m = (l + r) / 2;
    merge(a, l, m);
    merge(a, m + 1, r);
    int i = l, j = m + 1, k = 0;
    while (i <= m && j <= r) {
        if (a[i] <= a[j]) {
            tmp[k++] = a[i++];
        } else {
            tmp[k++] = a[j++];
            ans += m + 1 - i;
        }
    }
    while (i <= m) {
        tmp[k++] = a[i++];
    }
    while (j <= r) {
        tmp[k++] = a[j++];
    }
    for (int c = 0; c < k; c++) {
        a[c + l] = tmp[c];
    }
}
int a[1005];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        ans = 0;
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", a + i);
        }
        merge(a, 0, n - 1);
        printf("%d\n", ans);
    }
    return 0;
}