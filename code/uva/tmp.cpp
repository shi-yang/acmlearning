<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
int tmp[1000];
int ans;
void merge(int *a, int l, int r)
{
    if (l == r) {
        return;
    }
    int m = (l + r) / 2;
    merge(a, l, m);
    merge(a, m + 1, r);
    int i = l, j = m + 1, k = 0;
    while (i <= m && j <= r) {
        if (a[i] <= a[j]) {
            tmp[k++] = a[i++];
        } else {
            tmp[k++] = a[j++];
            ans += m + 1 - i;
        }
    }
    while (i <= m) {
        tmp[k++] = a[i++];
    }
    while (j <= r) {
        tmp[k++] = a[j++];
    }
    for (int c = 0; c < k; c++) {
        a[c + l] = tmp[c];
    }
}
int a[1005];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        ans = 0;
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", a + i);
        }
        merge(a, 0, n - 1);
        printf("%d\n", ans);
    }
    return 0;
}
=======
#include<cstdio>
#include<cstring>
#include<algorithm>
#include <bits/stdc++.h>

using namespace std;


const int maxn=10000;
char a[maxn];
int xishu[150],m[150];
long long MOD;
   int maxs;

void solve()
{
    int first=0;
 int len=strlen(a);
 memset(xishu,0,sizeof(xishu));
 memset(m,0,sizeof(m));
 for(int i=1;a[i]!=')';)
 {
     int cur=0;
     int flag=1;
     while(a[i]!='n'&&a[i]!=')')
     {
         char c=a[i];
         if(c=='+') {;}
         else if(c=='-')
         {
             flag=0;
         }
         else
         {
             cur=cur*10+(c-'0');
         }
         i++;
     }
     if(cur==0)
        cur=1;
     if(!flag)
        cur*=(-1);
     i++;
     int temp=0;
     if(a[i]=='/')
    {
       temp=0;
      xishu[temp]=cur;
       break;
    }
    else if(a[i]!='^')
        temp=1;
    else if(a[i]=='^')
    {
        i++;
        while(isdigit(a[i]))
        {
            temp=temp*10+a[i]-'0';
            i++;
        }
    }
    if(!first)
    {
        first=1;
        maxs=temp;
    }
    xishu[temp]=cur;
 }
    MOD=0;
    for(int i=0;i<len;i++)
    {
        if(a[i]=='/')
        {
            i++;
        for(;i<len;i++)
        {
            MOD=MOD*10+(a[i]-'0');
        }
        break;
       }
    }
 return ;
}

long long qpow(long long a,int b)//求a的b次方的值
{
    if(b==0)
        return 1;
    long long ans=qpow(a,b>>1);
    ans=ans*ans%MOD;
    if(b&1)
        ans=ans*a%MOD;
    return ans;
}

long long cal(long long num)//求n的num的时候的多项式的值
{
    if(num==0)
        return xishu[0];
    long long ans=0;
    for(int i=0;i<=100;i++)
    {
        if(xishu[i])
        {
            ans+=xishu[i]*qpow(num,i)%MOD;
        }
    }
    return ans;
}


int main()
{
   int kase=1;
    while(scanf("%s",a)==1)
    {
        int f=1;
     if(a[0]=='.')
        break;

     solve();
     for(long long k=0;k<=maxs;k++)
     {
         long long num=cal(k);
         if(num%MOD!=0)
         {
             f=0;
             break;
         }
     }
       if(f)
        printf("Case %d: Always an integer\n",kase++);
        else
        printf("Case %d: Not always an integer\n",kase++);
    }
    return 0;
}
>>>>>>> 16c3166bdb39006cac412609ffd8ebfc6adc537f
