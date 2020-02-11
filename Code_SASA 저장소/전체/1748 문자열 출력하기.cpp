#include<stdio.h>
char a[101];
int main(){
	int i=0;
	do{
		scanf("%c",&a[i]);
		if(a[i]!=' '&&a[i]!='\n')
		i++;
	}while(a[i]!='\n');
	printf("%s",a);
	return 0;
}
