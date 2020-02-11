#include<stdio.h> 
short n,arr[4][301],ans,i,j;
short DT[301][5]; // c,mod => 1,2,3,4(=1+3)
short max(int a,int b){
	return a>b?a:b;
}
void solve(){
	for(i=1;i<=3;i++)
		DT[1][i]=arr[i][1];
	DT[1][i]=arr[1][1]+arr[3][1];
	for(i=2;i<=n;i++){
		DT[i][1]=max(DT[i-1][2],DT[i-1][3])+arr[1][i];
		DT[i][2]=max(max(DT[i-1][1],DT[i-1][3]),max(DT[i-1][1],DT[i-1][4]))+arr[2][i];
		DT[i][3]=max(DT[i-1][1],DT[i-1][2])+arr[3][i];
		DT[i][4]=DT[i-1][2]+arr[1][i]+arr[3][i];
	}
	ans=max(max(DT[n][1],DT[n][2]),max(DT[n][3],DT[n][4]));
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=3;i++)
		for(j=1;j<=n;j++)
			scanf("%hd",&arr[i][j]);
	solve();
	printf("%hd",ans);
}
