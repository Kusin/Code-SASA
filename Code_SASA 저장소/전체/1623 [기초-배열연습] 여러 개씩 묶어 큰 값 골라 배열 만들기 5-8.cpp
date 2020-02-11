#include<stdio.h>
int n,g,d[200];
int max(int* a,int* b){
	int t=*a;
	for(int i=1;i<(int)(b-a);i++)
		if(t<*(a+i))
			t=*(a+i);
	return t;
}
int main(){
	scanf("%d%d",&n,&g);
	int k;
	for(int i=0;i<n;i++)
		scanf("%d",d+i);
	for(int i=0;i<n;i+=g)
		d[i]=max(d+i,d+i+g),printf("%d ",d[i]);
}
