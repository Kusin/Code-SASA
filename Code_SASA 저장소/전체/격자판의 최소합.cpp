#include<stdio.h>
int n,map[301][301];
int min(int a,int b){ return a<b?a:b;}
int readInt(){
    int sum = 0;
    char now=getchar_unlocked();
    while(now<=32) now=getchar_unlocked();
    while(now>=48){
        sum = sum*10 + now -48;
        now=getchar_unlocked();
    }
    return sum;
}
int main(){
    n=readInt();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
			map[i][j]=readInt();
        	if(i==1)
            	map[i][j]+=map[i][j-1];
            else if(j==1)
            	map[i][j]+=map[i-1][j];
            else 
            	map[i][j]+=min(map[i-1][j],map[i][j-1]);
            }
    printf("%d",map[n][n]);
}
