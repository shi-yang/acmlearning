#include <cstdio>  
#include <cstring>  
#include <string>  
#include <queue>  
using namespace std;  
int A, B, C;  
int vis[105][105];  
struct V{  
    int a;  
    int b;  
    int step;  
    string ans;  
}p,pp;  
queue <V> s;  
bool bfs()  
{  
    while (!s.empty())  
        s.pop();  
    vis[0][0] = 1;  
    p.a = 0;  
    p.b = 0;  
    p.step = 0;  
    s.push(p);  
    while (!s.empty())  
    {  
        p = s.front();  
        s.pop();  
        if (p.a == C || p.b == C)  
            return true;  
        int aa, bb;  
        for (int i = 1; i <= 6; i++){  
            if (1 == i)  
                aa = A, bb = p.b;  
            else if (2 == i)  
                aa = p.a, bb = B;  
            else if (3 == i){  
                if (p.a + p.b > A)  
                    bb = p.a + p.b - A, aa = A;  
                else  
                    bb = 0, aa = p.a + p.b;  
            }  
            else if (4 == i){  
                if (p.a + p.b > B)  
                    aa = p.a + p.b - B, bb = B;  
                else  
                    aa = 0, bb = p.a + p.b;  
            }  
            else if (5 == i)  
                aa = 0, bb = p.b;  
            else  
                aa = p.a, bb = 0;  
            if (!vis[aa][bb]){  
                vis[aa][bb] = 1;  
                pp.a = aa;  
                pp.b = bb;  
                pp.step = p.step + 1;  
                char c = i + '0';  
                pp.ans = "";  
                pp.ans += (p.ans + c);  
                s.push(pp);  
            }  
        }  
    }  
    return false;  
}  
void output(char c)  
{  
    if ('1' == c)  
        puts("FILL(1)");  
    else if ('2' == c)  
        puts("FILL(2)");  
    else if ('3' == c)  
        puts("POUR(2,1)");  
    else if ('4' == c)  
        puts("POUR(1,2)");  
    else if ('5' == c)  
        puts("DROP(1)");  
    else  
        puts("DROP(2)");  
}  
int main()  
{  
    while (scanf("%d%d%d", &A, &B, &C) != EOF)  
    {  
        memset(vis, 0, sizeof(vis));  
        if (bfs()){  
            printf("%d\n", p.step);  
     //       for (int i = 0; i < p.step; i++)  
       //         output(p.ans[i]);  
        }  
        else  
            puts("impossible");  
    }  
    return 0;  
}  