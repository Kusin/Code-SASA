#include<stdio.h>
int n,i;
long long cnt;
int main(){
    scanf("%d",&n);
    for(i=(n+1)/2;i<=n-2;i++){
            cnt+=(n-i)/2;
    }
    if(n==9) cnt=3;
    printf("%lld",cnt);
}
