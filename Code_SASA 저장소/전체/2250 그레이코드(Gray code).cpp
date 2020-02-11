#include<stdio.h>
char grcode[32],bncode[32];
void XOR(int a){
	if(bncode[a-1]==grcode[a])
		bncode[a]='0';
	else
		bncode[a]='1';
}
int num(int len){
	int x=1,sum=0;
	for(int i=len-1;i>=0;i--){
		sum+=(bncode[i]-'0')*x;
		x*=2;
	}
	return sum;
}
int main(){
	scanf("%s",grcode);
	int len;
	for(;grcode[len];len++);
	bncode[0]=grcode[0];
	for(int i=1;i<len;i++) XOR(i);
	printf("%d",num(len));
} 
