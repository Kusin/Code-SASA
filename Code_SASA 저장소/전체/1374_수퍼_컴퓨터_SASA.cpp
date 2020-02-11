#include<stdio.h>
#include<algorithm>
int n,k,cnt[100001],m[100001];
int main(){
     scanf("%d",&n);
     for(int i=1;i<=n;i++)
        scanf("%d",cnt+i);
    std::sort(cnt+1,cnt+n+1);
    m[1]=cnt[1];
    for(int i=2;i<=n;i++)
        m[i]=cnt[i]-cnt[i-1]-10;
    scanf("%d",&k);
    if(m[1]>=k)
        printf("%d",0);
    else{
        int i;
        for(i=2;i<=n;i++)
            if(m[i]>=k){
                printf("%d",cnt[i-1]+10);   
                break;
            }
        if(i==n+1)
        printf("%d",cnt[n]+10);
    }
}
