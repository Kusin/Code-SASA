#include<stdio.h>
#define N 30
int map[N+10][N+10],n,k,temp,flag;
int main(){
	scanf("%d%d",&n,&k);
	if(n%2){
		printf("no");
		return 0;
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++)for(int w=0;w<n;w++)
		{
			scanf("%1d",&temp);
			map[j][w]+=temp;
			map[j][w]%=2;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n/2;j++)
			if(map[j][i]!=map[n-1-j][i]){
				flag=1;
				break;
			}
	}
	for(int i=0;i<n/2;i++){
		for(int j=0;j<n/2;j++)
			if(map[i][j]!=map[i][n-1-j]){
				flag=1;
				break;
			}
	}
	if(flag) printf("no");
	else printf("yes");
}
