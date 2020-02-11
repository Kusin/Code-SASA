#include<stdio.h>
#define INF 987654321
int n,min=INF;
void f(int a,int b){
	if(a>n)
		return;
	if(a==n){
		min=b<min?b:min;
		return;	
	}
	f(a+1,b+1000);
	f(a+6,b+5000);
	f(a+20,b+18000);
	f(a+40,b+32000);
}
int main(){
	scanf("%d",&n);
	f(0,0);
	printf("%d",min);
}
