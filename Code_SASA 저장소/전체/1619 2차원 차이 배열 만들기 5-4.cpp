#include<stdio.h>
int n,m,k,d[1001][1001];
int main(){
	scanf("%d%d%d",&n,&m,&k); 
	int x1,y1,x2,y2,u;
	for(int i=0;i<k;i++){
		scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&u);
		d[x1][y1]=d[x1][y1]+u;
		d[x2+1][y2+1]=d[x2+1][y2+1]+u;
		d[x1][y2+1]=d[x1][y2+1]-u;
		d[x2+1][y1]=d[x2+1][y1]-u;
	}
	for(int i=0;i<n;i++,puts(""))
		for(int j=0;j<m;j++)
			printf("%d ",d[i][j]);
	puts("");	
	for(int i=1;i<n;i++)
		for(int j=1;j<m;j++)
			d[i][j]+=d[i-1][j]+d[i][j-1]-d[i-1][j-1];
	for(int i=0;i<n;i++,puts(""))
		for(int j=0;j<m;j++)
			printf("%d ",d[i][j]);	
} 
