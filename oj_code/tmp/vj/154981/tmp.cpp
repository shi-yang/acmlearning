#include <iostream>  
#include <stdio.h>  
#include <stdlib.h>  
#include<string.h>  
#include<algorithm>  
#include<math.h>  
#include<queue>  
using namespace std;  
typedef long long ll;  
const int N=105,INF=99999999;  
int l[N],tu[N][N];  
int n,m;  
int dis[N];  
bool vis[N];  
int spfa(int ll,int rr)  
{  
    memset(vis,0,sizeof(vis));  
    for(int i=0; i<=n; i++)  
        dis[i]=INF;  
    dis[0]=0;  
    queue<int>q;  
    q.push(0);  
    while(!q.empty())  
    {  
        int t=q.front();  
        q.pop();  
        vis[t]=0;  
        for(int i=1; i<=n; i++)  
        {  
            if(l[i]<ll||l[i]>rr)continue;  
            if(dis[t]+tu[t][i]<dis[i])  
            {  
                dis[i]=dis[t]+tu[t][i];  
                if(!vis[i])  
                {  
                    q.push(i);  
                    vis[i]=1;  
                }  
            }  
        }  
    }  
    return dis[1];  
}  
  
int main()  
{  
    cin>>m>>n;  
    for(int i=0; i<=n; i++)  
        for(int j=0; j<=n; j++)  
            tu[i][j]=i==j?0:INF;  
    for(int i=1; i<=n; i++)  
    {  
        int x;  
        scanf("%d%d%d",&tu[0][i],&l[i],&x);  
        while(x--)  
        {  
            int num;  
            scanf("%d",&num);  
            scanf("%d",&tu[num][i]);  
        }  
    }  
    int ans=INF;  
    for(int i=l[1]-m; i<=l[1]; i++)  
        ans=min(ans,spfa(i,i+m));  
    cout<<ans<<endl;  
    return 0;  
}  