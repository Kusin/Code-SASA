#include<stdio.h>
int a,b;
int f(int a,int b){
	if(a==b)
		return 0;
	if(a>b)
		return f(a/2,b)+1;
	if(a<b)
		return f(a,b/2)+1;
}
int main(){
	scanf("%d%d",&a,&b);
	printf("%d",f(a,b));
}
