#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 10050;
const int INF = 1000000001;

int value[505];
int w[505];
int d[maxn];
int min(int a, int b)
{
    return a > b ? b : a;
}
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int e, f;
        cin >> e >> f;
        int weight = f - e;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> value[i] >> w[i];
        }
        for(int i=0; i<=weight; ++i)
                d[i] = INF;
        d[0] = 0;
        for (int i = 0; i < n; i++)
            for (int j = w[i]; j <= weight; j++)
                if (d[j] > d[j - w[i]] + value[i])
                    d[j] = d[j - w[i]] + value[i];
        if (d[weight] == INF)
            printf("This is impossible.\n");
        else
            printf("The minimum amount of money in the piggy-bank is %d.\n", d[weight]);
    }
    return 0;
}
