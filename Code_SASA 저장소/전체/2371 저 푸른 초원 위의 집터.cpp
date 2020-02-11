#include<stdio.h>
int n,home[30][30],able[30][30],cnt,sum[200],count[200],ans,dr[4]={-1,0,1,0},dc[4]={0,-1,0,1};
bool safe(int a,int b){
	return (a>=0&&a<n)&&(b>=0&&b<n);
}
void dfs(int a,int b){
	sum[cnt]+=home[a][b];
	count[cnt]++;
	able[a][b]=0;
	for(int i=0;i<4;i++){
		int r=a+dr[i],c=b+dc[i];
		if(safe(r,c)&&able[r][c]==1)
			dfs(r,c);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			scanf("%d",&home[i][j]);
			if(home[i][j]<=100)
				able[i][j]=1;
			}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			if(able[i][j]){
				cnt++;
				dfs(i,j);
			}
		}
	if(!cnt) printf("no");
	else{
	for(int i=1;i<=cnt;i++)
		if(sum[i]>sum[ans])
			ans=i;
	printf("%d",count[ans]);
	}
}
