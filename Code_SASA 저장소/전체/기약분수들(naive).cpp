#include<stdio.h>
#define MAX 490010
int n,pn,pr[MAX/2];
bool isprime[MAX];
void getprime(){
    for(int i=2;i<=n;i++) isprime[i]=true;
    for(int i=2;i*i<=n;i++){
        if(isprime[i]){
            for(int j=i*i;j<=n;j+=i)
                isprime[j]=0;
        }
    }
    for(int i=2;i<=n;i++)
        if(isprime[i])
            pr[pn++]=i;
}
int eulerphi(int k){
    int i=0,ans=1;
    while((k>1)&&(i<pn)&&!isprime[k]){
        if(k%pr[i]!=0) i++;
        else{
            int t=1;
            while(k%pr[i]==0){
                t*=pr[i];
                k/=pr[i];
            }
            ans*=(t-t/pr[i]);
        }
    }
    if(isprime[k]) ans*=k-1;
    return ans;
}
int main(){
    scanf("%d",&n);
    getprime();
    long long ans=0;
    for(int i=1;i<=n;i++)
        ans+=eulerphi(i)/2;
    printf("%lld",ans);
}
