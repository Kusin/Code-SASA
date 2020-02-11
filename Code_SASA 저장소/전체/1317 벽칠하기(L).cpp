#include<stdio.h>
struct block{
	int col,w;
}IDT[262145];
int n,m,base=1;
void update(int a,int b,int c,int q){
	while(a<b){
		if(a%2==1){
			IDT[a].col=c;
			IDT[a].w=q;
			a++;
		}
		if(b%2==0){
			IDT[b].col=c;
			IDT[b].w=q;
			b--;
		}
		a>>=1,b>>=1;
	}
	if(a==b){
		IDT[a].col=c;
		IDT[a].w=q;
	}
	return;
}
int color(int a){
	int x=a; 
	while(a>0){
		a>>=1;
		if(IDT[a].w>IDT[x].w)
			x=a;
	}
	return IDT[x].col;
}
int main(){
	scanf("%d%d",&n,&m);
	while(base<n) base<<=1;
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		update(base+a-1,base+b-1,c,i);
	}
	for(int i=base;i<base+n;i++){
		printf("%d ",color(i));
	}
}
