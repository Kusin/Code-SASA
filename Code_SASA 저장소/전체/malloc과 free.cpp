#include<stdio.h> 
#include<stdlib.h>
// Made By Ku 2019
int m,n,dr[4]={1,0,-1,0},dc[4]={0,1,0,-1},cnt;
bool safe(int a,int b){
	return (a>=0)&&(a<m)&&(b>=0)&&(b<n);
}
void numberAmazonTreasureTrucks(int rows,int column,int **grid){
	grid[rows][column]=cnt+1;
	for(int i=0;i<4;i++){
		int r=rows+dr[i],c=column+dc[i];
		if(safe(r,c)&&grid[r][c]==1)
			numberAmazonTreasureTrucks(r,c,(int**)grid);
	}
}
int main(){
	scanf("%d%d",&m,&n);
	int i,j;
	int**grid;
	grid = (int**)malloc(sizeof(int*)*m);
	for(int i=0;i<m;i++)
		grid[i] = (int*)malloc(sizeof(int)*n);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&grid[i][j]);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			if(grid[i][j]==1){
				cnt++;
				numberAmazonTreasureTrucks(i,j,grid);
			}
	for(int i=0;i<m;i++)
		free(grid[i]);
	free(grid);
	printf("%d",cnt);
}
