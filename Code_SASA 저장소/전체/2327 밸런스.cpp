#include<stdio.h>
int n,c,a[101];
int min(int a,int b){
	return a<b?a:b;
}
int f(int mi,int id){
	if(mi<0) return 1<<30;
	if(id==0){
		if(mi-a[id]>=0) return mi-a[id];
		else return mi;
	}
	if(mi>a[id]*2.7) //a[0]+a[1]+...+a[id]<=a[id+2]-1==a[id]+a[id+1]-1<2.7*a[id] (fibonacci sequence)
		return f(mi-a[id],id-1);
	else
		return min(f(mi,id-1),f(mi-a[id],id-1));
}
int main(){
	scanf("%d%d",&n,&c);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	printf("%d",c-f(c,n-1));
}
