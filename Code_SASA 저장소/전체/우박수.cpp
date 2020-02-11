#include<stdio.h> //±¸°æ¸ð  
int a,b,mx,mi;
int DT[10001000];
int f(long long a){
	int cnt=0;
	while(a>10000000){
		if(a%2==1) a=3*a+1;
		else a=a/2;
		cnt++;
	}
	if(DT[a])
		return DT[a]+cnt;
	if(a%2==1) DT[a]=f(3*a+1)+1;
	else DT[a]=f(a/2)+1;
	return DT[a]+cnt;
}
int main(){
	scanf("%d%d",&a,&b);
	DT[1]=1; 
	for(int i=a;i<=b;i++){
		if(DT[i]) continue;
		if(mx<f(i)){
		mx=f(i);
			mi=i;
		}
	}
	printf("%d %lld",mi,mx);
}
