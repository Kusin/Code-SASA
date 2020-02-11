#include<stdio.h>
#include<queue>
int n,m,r,c,dr[4]={-1,1,2,2},dc[4]={2,2,-1,1},flag,min=144;
bool visit[14][14];
struct loc{
	int r1,c1;
};
bool safe(int a,int b){
	return (a>=1&&a<=n)&&(b>=1&&b<=n);
}
void dfs(int a,int b,int len){
	visit[a][b]=1;
	if(a==r&&b==c){
		flag=1;
		if(len<min)
			min=len;
		return;
	}
	for(int i=0;i<4;i++){
		int k=a+dr[i],m=b+dc[i];
		if(safe(k,m)&&visit[k][m]==0){
			dfs(k,m,len+1);
			visit[k][m]=0;
		}
	}
}
int main(){
	scanf("%d%d%d%d",&n,&m,&r,&c);
	for(int i=0,p,q;i<m;i++)
		scanf("%d%d",&p,&q),visit[p][q]=-1;
	dfs(1,1,0);
	printf("%d",flag?min:-1);
} 
