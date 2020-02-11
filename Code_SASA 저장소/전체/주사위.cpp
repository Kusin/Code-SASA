#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int n;
int main(){
	scanf("%d",&n);
	srand((int)time(NULL));
	for(int i=0,t;i<n;i++){
	scanf("%d",&t); 
	printf("¹øÈ£:%d\n",rand()%6+1);
	}
}
