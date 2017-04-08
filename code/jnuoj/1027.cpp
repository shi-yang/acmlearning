#include <stdio.h>
int a[100000];
int main()
{
    int n, i;
    unsigned long long s, j;
    while (scanf("%d", &n) != EOF) {
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (i = 0; i < n; i++) {
            if (a[i] < 4)
                printf("%d\n", a[i]);
            else {
                j = a[i];
                s = (j-3)*(j-2)/2*(j-1)/3*j/4;
                printf("%lld\n", s + j);
            }
        }
    }
    return 0;
}
