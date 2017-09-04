/*
  就在这儿学到了并查集的路径压缩概念，不压缩会超时。
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 100005;
int uf[maxn];
int cnt[maxn];
int ans;
int root(int x)
{
    /* 就这个函数，被注释掉的代码会超时，而没被注释的代码可以AC。
    while (x != uf[x])
        x = uf[x];
    return x;
    */
    return x == uf[x] ? x : uf[x] = root(uf[x]);
}
void unioned(int a, int b)
{
    a = root(a), b = root(b);
    if (a == b) {
        return ;
    }
    uf[a] = b;
    cnt[b] += cnt[a];
    ans = max(ans, cnt[b]);
}
int main()
{
    int n;
    while(~scanf("%d", &n)) {
        for (int i = 1; i < maxn; i++) {
            uf[i] = i, cnt[i] = 1;
        }
        ans = 0;
        int a, b;
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a, &b);
            unioned(a, b);
        }
        if (!n)
            ans = 1;
        printf("%d\n", ans);
    }
    return 0;
}
