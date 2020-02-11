#include<stdio.h>
#include<math.h>
int main(int x,int y,int c){
	scanf("%d%d%d",&x,&y,&c);
	printf("%d",(int)floor(c*(sqrt(x)-sqrt(y))));
}
