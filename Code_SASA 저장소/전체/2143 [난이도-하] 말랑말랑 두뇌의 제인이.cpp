#include<bits/stdc++.h> // ¹Ì¿Ï¼º  
using namespace std;
int n,arr[30][30],dr[4]={1,0,-1,0},dc[4]={0,1,0,-1},cnt,check[30][30];
bool safe(int a,int b){
	return (a>=0)&&(a<n)&&(b>=0)&&(b<n);
}
void dfs(int r,int c){
	arr[r][c]=cnt+1;
	for(int i=0;i<4;i++){
		int a=r+dr[i],b=c+dc[i];
		if(!safe(a,b)) continue;
		if(arr[a][b]) check[r][c]+=(i+1)*(i+1);
		if(arr[a][b]==1) dfs(a,b);
	}
}
int main(){
	char str[25];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",str);
		for(int j=0;j<n;j++){
			if(str[j]=='o')
				arr[i][j]=1;
			else
				arr[i][j]=0;
		}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			if(arr[i][j]==1){
				cnt++;
				dfs(i,j);
			}
		}
	for(int i=0;i<n;i++,puts(""))
		for(int j=0;j<n;j++)
			printf("%d",arr[i][j]);
}
