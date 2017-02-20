#include <stdio.h>
int main()
{
	int t, n, i, j;
	float d;
    scanf("%d", &t);
	while (t--) {
        scanf("%d", &n);
		int a[n][9];
		float t1, t2, t3, step;
        d = 0;
		for (i = 0; i < n; i++) {
			scanf("%d:%d %d %d %d:%d %d %d:%d",
				&a[i][0], &a[i][1], &a[i][2],
				&a[i][3], &a[i][4], &a[i][5],
				&a[i][6], &a[i][7], &a[i][8]);
		}
		for (i = 0; i < n; i++) {
			t1 = a[i][0] * 60 + a[i][1];
			t2 = a[i][3] * t1 + a[i][4] * 60 + a[i][5];
			t3 = a[i][6] * t1 + a[i][7] * 60 + a[i][8];
            d += (double) t3 * a[i][2] * 400 / (a[i][2] * t2);
		}
        printf("%.1f\n", d / n);
	}
	return 0;
}
