#include<stdio.h>
#include<string.h>
char a[11];
int i; 
int main(){
	scanf("%s",a);
	for(i=0;i<strlen(a);i++)
	  if(a[i]=='t')
	   printf("%d ",i+1);
	return 0;
} 
