#include<stdio.h>
int n;
void b_num(int k){
	if(k==0)
		return;
	b_num(k/2);
	printf("%d",k%2);
}
void input(){
	scanf("%d",&n);
}
int main(){
	input();
	if(n==0)
		printf("%d",0);
	else
		b_num(n);
}
