#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct node
{
    int u,v,w,flow,cab,nt;
} e[50000];;8 
int ft[110],d[110],inq[110],p[110];
int cnt,n,m;
int cc,ff;
void add(int u,int v,int cost,int cab)
{
    e[cnt].u=u;   //对每个点添加一条正费用边，以及下面的负费用边
    e[cnt].v=v;
    e[cnt].w=cost;
    e[cnt].cab=cab;
    e[cnt].flow=0;
    e[cnt].nt=ft[u];
    ft[u]=cnt++;

    e[cnt].u=v;
    e[cnt].v=u;
    e[cnt].w=-cost;
    e[cnt].cab=0;
    e[cnt].flow=0;
    e[cnt].nt=ft[v];
    ft[v]=cnt++;
}
void ek()
{
    queue<int> q;
    cc=ff=0;
    int i,j;
    for (;;)
    {
        for (i=0;i<=n+1;i++)
            d[i]=1<<30;
        d[0]=0;
        memset(inq,0,sizeof inq);
        memset(p,-1,sizeof p);
        q.push(0);
        while (!q.empty()) //SPFA搜最短路
        {
            int u=q.front();
            q.pop();
            inq[u]=0;
            for (j=ft[u];j>=0;j=e[j].nt)
            {
                int nx=e[j].v;
                if (e[j].cab>e[j].flow && d[nx]>d[u]+e[j].w)
                {
                    d[nx]=d[u]+e[j].w;
                    p[nx]=j;  //这里不能记录前端点，因为端点指向的边不止一点，因此只能记录该点对应的是哪条边
                    if (!inq[nx])
                    {
                        q.push(nx);
                        inq[nx]=1;
                    }
                }
            }
        }
        if (d[n+1]>=(1<<30)) break;
        int a=1<<30;
        for (i=p[n+1];i>=0;i=p[e[i].u])
        {
            if (a>e[i].cab-e[i].flow)
                a=e[i].cab-e[i].flow;
        }
        for (i=p[n+1];i>=0;i=p[e[i].u])
        {
            e[i].flow+=a;
            e[i^1].flow-=a;//用异或可以使得当前i很快找到对应的那条负费用边 或者 正费用边，因为添加边的时候都是两条两条的加。
        }
        cc+=d[n+1]*a;
        ff+=a;
    }
}
int main()
{
    int i,j;
    while (scanf("%d",&n))
    {
        if (n==0) break;
        cnt=0;
        scanf("%d",&m);
        int a,b,c;
        memset(ft,-1,sizeof ft);
        for (i=1;i<=m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c,1);
            add(b,a,c,1);
        }
        add(0,1,0,2); //添加超级原点和终点，这样就方便最后的答案计算。
        add(n,n+1,0,2);
        ek();
        if (ff>=2)
            printf("%d\n",cc);
        else
            puts("Back to jail");
    }
    return 0;
}