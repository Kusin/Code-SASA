#include<stdio.h>
int n;
char a[200];
void f(int k,int flag){
	if(flag){
		if(k<1){
		f(1,0);
		return;
		}
		a[k]='*';
		f(k-1,flag);
	} 
	else{
		if(k>n)
			return;
		puts(a+1);
		a[k]=' ';
		f(k+1,0);
	}
	
}
int main(){
	scanf("%d",&n);
	f(n,1);
}
