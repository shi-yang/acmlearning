#include <stdio.h>
int main()
{
	int n, i, t, max, min;
	while (scanf("%d", &n) != EOF) {
		int a[n];
		for (i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			if (a[i] == 1)
				min = i + 1;
			if (a[i] == n)
				max = i + 1;
		}
		if (min > max) {
			t = max;
			max = min;
			min = t;
		}
		if (n - max >= min)
			printf("%d\n", n - min);
		else
			printf("%d\n", max - 1);
	}
	return 0;
}
