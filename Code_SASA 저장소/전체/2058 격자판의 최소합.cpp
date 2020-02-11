#include<stdio.h>
int n,map[301][301];
int readInt(){
	int sum = 0;
	char now=getchar();
	while(now<=32) now=getchar();
	while(now>=48){
		sum = sum*10 + now -48;
		now=getchar();
	}
	return sum;
}
int min(int a,int b){
	return a<b?a:b;
}
void solve(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=1||j!=1)
				map[i][j]+=min(map[i-1][j],map[i][j-1]);
	printf("%d",map[n][n]);
}
int main(){
	n=readInt();
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			if(!i||!j)
				map[i][j]=1<<30;
			else if(i==1&&j==1)
				map[i][j]=readInt();
			else if(i!=1||j!=1)
				map[i][j]=readInt(),map[i][j]+=min(map[i-1][j],map[i][j-1]);
	printf("%d",map[n][n]);
}
