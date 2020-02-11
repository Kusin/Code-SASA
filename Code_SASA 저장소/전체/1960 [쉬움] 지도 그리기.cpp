#include<stdio.h>
char arr[2001][2001],dr[4]={0,-1,0,1},dc[4]={-1,0,1,0};
int r=1000,c=1000,r1=1000,c1=1000,r2=1000,c2=1000;
int setdir(char c){
	switch(c){
		case 'l': return 0;
		case 'u': return 1;
		case 'r': return 2;
		case 'd': return 3;
	}
}
int main(){
	char t;
	arr[r][c]='s';
	for(int i=0,w,d;i<20;i++){
		scanf(" %1c",&t);
		if(t=='e')
			break;
		d=setdir(t);
		scanf("%d",&w);
		for(int i=1;i<=w;i++){
			r+=dr[d],c+=dc[d];
			arr[r][c]='o';
		}
	}
	for(int i=0;i<=2000;i++)
		for(int j=0;j<=2000;j++)
			if(arr[i][j]){
				if(i<r1)r1=i;
				if(i>r2)r2=i;
				if(j<c1)c1=j;
				if(j>c2)c2=j;
			}
	for(int i=r1;i<=r2;i++,puts(""))
		for(int j=c1;j<=c2;j++){
			if(arr[i][j])
				putchar(arr[i][j]);
			else
				putchar('_');
		}
	return 0;
}
