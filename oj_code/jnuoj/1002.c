#include <stdio.h>
int main()
{
    int a, b, c, d, e;
    float f1, f2, f3;
    while (scanf("%d%d%d%d%d", &a, &b, &c, &d, &e) != EOF) {
        f1 = (a + b) * 2.4 + c + d + e;
        f2 = c * 2.4 + a + b + d + e;
        f3 = (d + e) * 2.4 + a + b + c;
        f1 = (f1 > f2) ? f1 : f2;
        f1 = (f1 > f3) ? f1 : f3;
        printf("%.1f\n", f1);
    }
    return 0;
}
