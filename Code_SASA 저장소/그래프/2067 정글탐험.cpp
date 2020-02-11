#include<stdio.h>
int n,map[301][301];
int max(int a,int b){ return a>b?a:b;}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            scanf("%d",&map[i][j]);
    		if(map[i][j]==-1)
            	map[i][j]=0;
            else{
            	int k=max(map[i-1][j],map[i][j-1]);
            	if((i==1&&j==1)||k)
            		map[i][j]+=k;
            	else 
            		map[i][j]=0;
            	}
            }
    printf("%d",map[n][n]>0?map[n][n]:-1);
}
