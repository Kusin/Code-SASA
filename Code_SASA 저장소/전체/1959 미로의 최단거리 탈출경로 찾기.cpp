#include<stdio.h> //dfs ¹æ¹ý  
int h,w,s1,s2,e1,e2,dr[4]={1,0,-1,0},dc[4]={0,1,0,-1},ans=900,flag;
char maze[31][31];
int chk[31][31],memo[31][31];
bool safe(int a,int b){
	return a>=0&&a<h&&b>=0&&b<w;
}
void dfs(int r,int c,int len){
	if(len>=memo[r][c])
		return;
	if(r==e1&&c==e2){
		flag=1;
		if(len<ans)
			ans=len;
		return;
	}
	chk[r][c]=1;
	memo[r][c]=len;
	for(int i=0;i<4;i++){
		int x=r+dr[i],y=c+dc[i];
			if(safe(x,y)&&maze[x][y]=='.'&&chk[x][y]==0)
				dfs(x,y,len+1),chk[x][y]=0;
			}
}
int main(){
	scanf("%d %d\n",&h,&w);
	for(int i=0;i<h;i++)
	scanf("%s",maze[i]);
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++){
			memo[i][j]=900;
			if(maze[i][j]=='S')
				s1=i,s2=j;
			else if(maze[i][j]=='G')
				e1=i,e2=j,maze[i][j]='.';
		}
	dfs(s1,s2,0);
	printf("%d",flag?ans:-1); 
}
