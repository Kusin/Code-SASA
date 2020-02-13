#include<stdio.h>
#include<vector>
#define MAX 10000000
using namespace std;
int n,cnt,m;
vector<int> query;
bool prime[MAX+1];
void R(int&k){
    char now=getchar_unlocked();
    int sum=0;
    while(now<=32) now=getchar_unlocked();
    while(now>=48){
        sum=sum*10+now-48;
        now=getchar_unlocked();
    }
    k=sum;
} 
int main(){
    R(n);
    for(int i=0,k;i<n;i++){
        R(k);
        query.push_back(k);
        if(k>m)
            m=k;
    }
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
    printf("%d",cnt);
}
