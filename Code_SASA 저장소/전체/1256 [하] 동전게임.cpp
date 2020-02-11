#include<stdio.h>
int sol(int m,int n){
	if((n-m)%2)
		return 0; 
	if(m==n)
		return 2;
	if(m==1&&n>1)
		return 0;
	return sol(m-1,n-1)+sol(m+1,n-1);
	
}
int main(){
    int n,m;
    scanf("%d %d",&m,&n);
   	printf("%d",sol(m,n));
}
