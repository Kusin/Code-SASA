#include<stdio.h> 
int n,base=1,m,k,x,a,b,IDT[800000];
int R(){
	char now=getchar_unlocked();
	int sum=0;
	while(now<=32) now=getchar_unlocked();
	while(now>=48){
		sum=sum*10+now-48;
		now=getchar_unlocked();
	}
	return sum;
} 
void update(int a,int key){
	int chg=key-IDT[a];
	while(a>0){
		IDT[a]+=chg;
		a>>=1;
	}
}
int id_sum(int a,int b){
	int sum=0;
	while(a<b){
		if(a%2==1)
			sum+=IDT[a],a++;
		if(b%2==0)
			sum+=IDT[b],b--;
		a>>=1; b>>=1;
	}
	if(a==b)
		sum+=IDT[a];
	return sum;
}
main(){
	n=R();
	while(base<n) base<<=1;
	for(int i=base; i<base+n ;i++)
		IDT[i]=R();
	for(int i=base-1;i>=1;i--)
		IDT[i]=IDT[i*2]+IDT[i*2+1];
	m=R(); k=R();
	for(int i=0;i<m+k;i++){
		x=R();
		a=R();
		b=R();
		if(x==0){
			update(base+a-1,b);
		}
		else{
			printf("%d\n",id_sum(base+a-1,base+b-1));
		}
	}
}
