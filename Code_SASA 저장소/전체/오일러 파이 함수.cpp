#include<stdio.h> // from 1852 기약분수들  
#define MAX 490010
int n,pn,spf[MAX],Prime[MAX]; // pn=prime number, spf=smallest prime factor
void EulerSieve(int m){
    for(int i=2;i<=m;i++){
        if(!spf[i]) 
            spf[i]=Prime[pn++]=i;
        for(int j=0;i*Prime[j]<=m;j++){
            spf[i*Prime[j]]=Prime[j];
            if(i%Prime[j]==0) break;
        }
    }
}
int eulerphi(int k){
    int ans=1;
    while(k>1){
        int t=spf[k],temp=1;
        while(spf[k]==t){
            k/=t;
            temp*=t;
        }
        ans*=(temp-temp/t);
    }
    return ans;
}
int main(){
    scanf("%d",&n); 
    EulerSieve(n);
    long long ans=0;
    for(int i=1;i<=n;i++)
        ans+=eulerphi(i)/2;
    printf("%lld",ans);
}

