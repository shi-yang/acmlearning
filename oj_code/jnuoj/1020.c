#include <stdio.h>
int main()
{
	int t, i, j, s;
	while (scanf("%d", &t) != EOF) {
		char n[t][1000000];
		for (i = 0; i < t; i++)
			scanf("%s", &n[i]);
		for (i = 0; i < t; i++) {
			j = 0;
			s = 0;
			while (n[i][j] != '\0') {
				if (n[i][j] == '1')
					s++;
				j++;
			}
			printf("%d\n", s);
		}
	}
	return 0;
}
