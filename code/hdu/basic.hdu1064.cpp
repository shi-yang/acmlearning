#include <cstdio>
#include <iostream>
using namespace std;
float bal[12];
int main()
{
    float sum = 0;
    for (int i = 0; i < 12; i++) {
        cin >> bal[i];
        sum += bal[i];
    }
    printf("$%.2f\n", sum / 12);
    return 0;
}
