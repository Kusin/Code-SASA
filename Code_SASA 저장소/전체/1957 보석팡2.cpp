#include<stdio.h>
int kind, max,visit[12][12], arr[12][12],cnt;
void vsp(int ,int );
bool check(int ,int ,int ,int );
int main(){
	int r,c,i,j;
	scanf("%d%d",&r,&c);
	for(i=1;i<=r;i++)
	 for(j=1;j<=c;j++)
	  scanf("%d",&arr[i][j]);
	for(i=1;i<=r;i++)
	 for(j=1;j<=c;j++){
	 	if(visit[i][j]==0&&arr[i][j])
	 	{
	 		cnt=0;
	 	  vsp(i,j);
	 	 if(cnt>max){
	 	 	kind=arr[i][j];
	 	 	max=cnt;
		  }
	 }
	 }
  if(max>=3)
   printf("%d %d",kind,max);
   else
   printf("%d",0);
	return 0;
}
void vsp(int x,int y){
	visit[x][y]=1; cnt++;
	
	if(check(x,y,1,0))
	  vsp(x+1,y);
	if(check(x,y,0,1))
	  vsp(x,y+1);
	if(check(x,y,-1,0))
	  vsp(x-1,y);
	if(check(x,y,0,-1))
	  vsp(x,y-1);
	 return; 
}
bool check(int x,int y,int a,int b){
	return arr[x+a][y+b]&&arr[x+a][y+b]==arr[x][y]&&visit[x+a][y+b]==0;
}

