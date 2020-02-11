#include<stdio.h>
int w,goal;
float r;
long long day=1;
int main(){
	scanf("%d %f %d",&w,&r,&goal);
	float cur=(float)w;
	while(cur>goal){
		cur=cur*(100-r)/100;
		day++;
	}
	printf("%d",day);
}
