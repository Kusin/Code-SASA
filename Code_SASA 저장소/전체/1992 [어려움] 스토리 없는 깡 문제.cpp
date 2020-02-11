#include<stdio.h> //실패 ? .. ==> 문제오류. x==0 과 x==1 로 하면 안되고 
				  // x==0과 else문으로 처리해야 한다. 
int n,base=1,m,k,x,a,b,IDT[800000];
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
int main(){
	scanf("%d",&n);
	while(base<n) base<<=1;
	for(int i=base; i<base+n ;i++)
		scanf("%d",IDT+i);
	for(int i=base-1;i>=1;i--)
		IDT[i]=IDT[i*2]+IDT[i*2+1];
	scanf("%d%d",&m,&k);
	for(int i=0;i<m+k;i++){
		scanf("%d%d%d",&x,&a,&b);
		if(x==0){
			update(base+a-1,b);
		}
		else{
			printf("%d\n",id_sum(base+a-1,base+b-1));
}
	}
}
