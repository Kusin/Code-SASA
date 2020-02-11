#include<stdio.h>
int n;
char a[3]="**";
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++)
		   printf(" ");
		puts(a);
	}
	return 0; 
}
