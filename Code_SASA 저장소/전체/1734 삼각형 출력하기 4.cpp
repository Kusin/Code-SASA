#include<stdio.h>
int n;
char a[200];
void f(int k,int flag){
	if(flag){
		if(k>n){
			f(k-1,0);
			return; 
		}
		a[k]='*';
		puts(a+1);
		f(k+1,1);
	} 
	else{
		if(k==1)
			return;
		a[k]='\0';
		puts(a+1);
		f(k-1,0);
	}
}
int main(){
	scanf("%d",&n);
	f(1,1);
}
