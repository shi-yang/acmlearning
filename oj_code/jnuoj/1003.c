#include <stdio.h>

int main()
{
    int n, i, t;
    while (scanf("%d", &n) != EOF) {
        int x[n], y[n];
        t = 0;
        float k1, k2, k3;
        for (i = 0; i < n; i++) {
            scanf("%d%d", &x[i], &y[i]);
        }
        k1 = (float)(y[1] - y[0]) / (x[1] - x[0]);
        k2 = (float)(y[2] - y[0]) / (x[2] - x[0]);
        for (i = 3; i < n; i++) {
            k3 = (float)(y[i] - y[0]) / (x[i] - x[0]);
            if (k3 != k1) {
                t = i;
                break;
            }
        }
        if (t != 0 && k1 == k2) {
            printf("%d %d\n", x[t], y[t]);
            continue;
        }
        if (t != 0 && k2 == k3) {
            printf("%d %d\n", x[1], y[1]);
            continue;
        }
        if (t == 0) {
            printf("%d %d\n", x[2], y[2]);
            continue;
        }
        if (t != 0 && k1 != k2 && k2 != k3) {
            printf("%d %d\n", x[0], y[0]);
            continue;
        }
    }
    return 0;
}
