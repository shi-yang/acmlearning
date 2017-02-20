#include <stdio.h>
int main()
{
	int n, h;
	while (scanf("%d%d", &n, &h) != EOF) {
		int a[n], i, width = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		for (i = 0; i < n; i++) {
			if (a[i] <= h)
				width++;
			else
				width += 2;
		}
		printf("%d\n", width);
	}
	return 0;
}
