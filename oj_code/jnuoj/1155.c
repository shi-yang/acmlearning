#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        char s[10];
        while (n--) {
            scanf("%s", s);
            printf("%c\n", s[1]);
        }
    }
    return 0;
}
