#include<stdio.h>
#define K 1024
long long int k;
int cnt;
int main(){
	scanf("%lld",&k);
	while(k>=1024&&cnt<4) k/=1024,cnt++;
	printf("%d ",k);
	switch(cnt){
		case 0:printf("%s","Byte"); break;
		case 1:printf("%s","KB"); break;
		case 2:printf("%s","MB"); break;
		case 3:printf("%s","GB"); break;
		default: printf("%s","TB");
	}
}
