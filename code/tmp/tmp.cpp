#include <stdio.h>
int main()
{
    int t,i,j,k,n,q,p;
    long long temp=0,x,sum;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        long long a[n];
				sum=0;
        for(i=0;i<n;i++){
            scanf("%lld",&a[i]);
            sum+=a[i];
        }
        if(sum%2==1){
            x=1000000000;
            for(p=0;p<n;p++){
                if(a[p]%2==1){
                    if(a[p]<x)
                    {
                        x=a[p];
                    }
                }
            }
            sum-=x;
        }
        printf("%lld\n",sum);

    }
    return 0;

}
