#include<stdio.h>
int Eulerphi(int );
int main(){
	int num;
	scanf("%d",&num);
	printf("%d",Eulerphi(num));
}
int Eulerphi(int n){
	int phi=n,temp=n;
	for(int i=2;i*i<=temp;i++)
			if(temp%i==0){
				while(temp%i==0) temp/=i;
				phi=phi*(i-1)/i;
			}
	if(temp!=1) phi = phi * (temp-1) /temp;
	return phi;
}
