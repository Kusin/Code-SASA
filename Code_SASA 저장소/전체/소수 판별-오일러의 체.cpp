#include<stdio.h>
#include<vector>
#define MAX 10000010
using namespace std;
int n,cnt,m;
bool prime[MAX];
vector<int> query;
int pn,spf[MAX],Prime[MAX]; // pn=prime number, spf=smallest prime factor
void R(int&k){
    char now=getchar();
    int sum=0;
    while(now<=32) now=getchar();
    while(now>=48){
        sum=sum*10+now-48;
        now=getchar();
    }
    k=sum;
} 
void Eratosthenes(){
	prime[1]=1,prime[0]=1,prime[2]=0;
    for(long long i=3;i*i<=m;i+=2){
        if(!prime[i]){
            for(long long j=i*i;j<=m;j+=i)
                prime[j]=1;
        }
    }
    for(int i=0;i<n;i++){
        if((query[i]==2||(query[i]%2))&&!prime[query[i]])
            cnt++;
    }
}
void EulerSieve(){
	for(int i=2;i<=m;i++){
		if(!spf[i])	
			spf[i]=Prime[pn++]=i;
		for(int j=0;i*Prime[j]<=m;j++){
			spf[i*Prime[j]]=Prime[j];
			if(i%Prime[j]==0) break;
		}
	}
	for(int i=0;i<n;i++){
		if(spf[query[i]]==query[i])
			cnt++;
	}
}
int main(){
    R(n);
    for(int i=0,k;i<n;i++){
        R(k);
        query.push_back(k);
        if(k>m)
            m=k;
    }
    EulerSieve();
    printf("%d",cnt);
}
