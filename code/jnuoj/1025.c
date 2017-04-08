#include <stdio.h>
int main()
{
    int x;
    char y;
    while (scanf("%c%d", &y, &x) != EOF) {
        if (x % 2 != 0)
        y = (y != 'A') ? 'A' : 'B';
        printf("%c\n", y);
        getchar();
    }
    return 0;
}
