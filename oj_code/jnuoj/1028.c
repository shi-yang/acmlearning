#include <stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n) != EOF) {
        if(n % 2)
            printf("0\n");
        else
        	printf("%d\n", (n - 1) / 4);
    }
    return 0;
}
