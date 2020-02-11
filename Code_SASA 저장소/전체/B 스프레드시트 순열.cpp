#include<stdio.h>
long long n;
char a[30]=" ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void f(long long n){
	if(n<0) return;
	f(n/26-1);
	printf("%c",a[n%26+1]);
}
int main(){
	scanf("%lld",&n);
	if(n-1) f(n-1);
	else printf("A");
}
