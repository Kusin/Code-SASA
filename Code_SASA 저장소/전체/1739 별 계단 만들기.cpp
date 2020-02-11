#include<stdio.h>
int n;
char c[110];
void f(int n){
	if(n<1)
		return;
	puts(c+n);
	f(n-1);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++)
		c[i]=' ';
	c[n]='*',c[n+1]='*';
	f(n); 
}
