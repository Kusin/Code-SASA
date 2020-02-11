#include<stdio.h>
#include<queue>
using namespace std;
queue<int> q;
int n;
int a[5],b[32][32],visit[32],flg;
int f(void){
    int i=0,k=1,sum=0;
    while(i<5){
        sum+=a[i]*k;
        i++,k*=2;
    }
    return sum;
}
void bfs(int k){
    q.push(k);
    visit[k]=1;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<32;i++)
            if(b[x][i]&&!visit[i]){
              q.push(i),visit[i]=visit[x]+1;
                if(i==31){
                    flg=1;
                    return;
                }
            }
    }
}
int main(){
    for(int i=0;i<=31;i++){
        b[i][i^7]=1;
        b[i][i^14]=1;
        b[i][i^28]=1;
    }
    for(int i=0;i<5;i++)
        scanf("%d",a+i);
    n=f();
    bfs(n);
    printf("%d",visit[31]?visit[31]-1:-1);
}
