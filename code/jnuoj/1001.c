#include<stdio.h>
int main()
{
	float k, b;
	while (scanf("%f%f", &k, &b) != EOF) {
		if (k<0) printf("Decreasing\n");
		else if (k>0) printf("Increasing\n");
		else if (k == 0) printf("Constant\n");
	}
	return 0;
}
