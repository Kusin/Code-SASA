#include<stdio.h>
int main(){
	int loc,n,a[32];
	scanf("%d",&n); 
	loc=0;
	if(!n)
	printf("%d",0);
	else
	  while(n>0){
		a[loc]=n%2;
		n/=2;
		loc++;
	}
	for(int i=loc-1;i>=0;i--)
	 printf("%d",a[i]);
	return 0;
}
