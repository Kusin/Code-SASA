#include<stdio.h>
int n,k,base=1;
struct tree{
	int val,num;
}IDT[400000];
struct tree maxid(struct tree a,struct tree b){
	if(a.val==b.val)
		return a.num<b.num?a:b;
	return a.val>b.val?a:b;
}
int maxnode(int a,int b){
	a+=base-1;
	b+=base-1;
	struct tree ans;
	ans.num=0;ans.val=-1;
	while(a<b){
		if(a%2==1){
			ans=maxid(IDT[a],ans);
			a++;
		}
		if(b%2==0){
			ans=maxid(IDT[b],ans);
			b--;
		}
		a>>=1;
		b>>=1;
	}
	if(a==b) ans=maxid(IDT[a],ans);
	return ans.num;
}
int main(){
	scanf("%d%d",&n,&k);
	while(base<n) base<<=1;
	for(int i=base;i<base+n;i++){
		scanf("%d",&IDT[i].val);
		IDT[i].num=i-base+1;
	}
	for(int i=base-1;i>=1;i--){
		IDT[i]=maxid(IDT[2*i],IDT[2*i+1]);
	}
	for(int i=1;i<k;i++)
		printf("%d ",maxnode(1,i));
	for(int i=1;i<=n-k+1;i++)
		printf("%d ",maxnode(i,i+k-1));
	for(int i=n-k+2;i<=n;i++)
		printf("%d ",maxnode(i,n));
}
