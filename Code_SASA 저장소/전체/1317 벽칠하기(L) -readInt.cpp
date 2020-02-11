#include<stdio.h>
struct block{
	int col,w;
}IDT[262145]; //최대 base 값은 400000으로 잡아도 되나,최적화시켰다. 
int n,m,a,b,c,base=1;
int readInt(){
	char num=getchar_unlocked();
	int sum=0;
	while(num<=32) num=getchar_unlocked();
	while(num>=48){
		sum=sum*10+num-48;
		num=getchar_unlocked();
	}
	return sum;
}
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
	n=readInt(); m=readInt();
	while(base<n) base<<=1;
	for(int i=1;i<=m;i++){
		a=readInt();
		b=readInt();
		c=readInt();
		update(base+a-1,base+b-1,c,i);
	}
	for(int i=base;i<base+n;i++){
		printf("%d ",color(i));
	}
}
