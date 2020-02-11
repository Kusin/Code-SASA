#include<stdio.h>
#define M 2005
int n;
short tr(int k,int a,int b,int c,int d,int e){
	if(k==n)
		return (short)a;
	return tr(k+1,b,c,d,e,(b+c+e)%2005);
}
int main(){
	scanf("%d",&n);
	printf("%hd",tr(0,1,2,4,6,9));
}
