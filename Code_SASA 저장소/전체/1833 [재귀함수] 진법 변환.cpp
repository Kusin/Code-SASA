#include<stdio.h>
char num[27]={"0123456789ABCDEFGHIJKLMNOP"};
int n,m;
void input(){
	scanf("%d%d",&n,&m);
}
void chg(int k,int p){
	if(k==0)
		return;
	chg(k/p,p);
	printf("%c",num[k%p]);
}
int main(){
	input();
	if(n==0)
		printf("%d",n);
	else
		chg(n,m);
}
