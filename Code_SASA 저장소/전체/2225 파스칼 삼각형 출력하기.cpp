#include<stdio.h>
int n,p[26][26];
void print(int n,int k){
	if(k>n){
		printf("\n");
		return;
	}
	printf("%d ",p[n][k]);
	print(n,k+1);
}
void fill(int n,int k){
	if(k>n)
		return;
	if(n==1)
		p[n][k]=1;
	else
		p[n][k]=p[n-1][k-1]+p[n-1][k];
	fill(n,k+1);
}
void pascal(int k){
	if(k>n)
		return;
	fill(k,1);
	print(k,1);
	pascal(k+1);
}
int main(){
	scanf("%d",&n);
	pascal(1);
}
