#include<stdio.h>
char a[21],b[21],c[21];
int main(){
	int i=0;
scanf("%s",a);
	i=0;	
   while(a[i]!='\0'){
   	b[i]=(a[i]+2)%128;
		c[i]=((a[i]*7)%80+48)%128;
		i++;
		}
    puts(b);
    puts(c); 
	return 0;
}
