#include<stdio.h>
int main(){
	int mon=5000,a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int x=1000*a+800*b+500*c;
	if(x>5000) printf("TT");
	else{
		mon-=x;
		printf("%d %d",mon/1000,(mon%1000)/100);
	}
}
