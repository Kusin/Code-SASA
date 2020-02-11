#include<stdio.h>
#include<math.h>
int a,b,x,arr[10000001],len=1;
int d2,d5,d10,lst=1;
int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
void solve(){
	x=a/b;
	a=a%b;
	int t=gcd(a,b);
	a/=t;
	b/=t;
	int tmp=b;
	while(tmp%2==0) tmp/=2,d2++;
	while(tmp%5==0) tmp/=5,d5++;
	if(tmp==1){
		len=0;
		return;
//		printf("%.16g",x+(double)a/b);
//		if(a==0) putchar('.');
	}
else{
	if(d2>d5) 
		d10=d2,lst=a*(int)pow(5.0,(double)(d2-d5));
	else 
		d10=d5,lst=a*(int)pow(2.0,(double)(d5-d2));
//	printf("%.16g",x+(lst/tmp)/pow(10.0,(double)d10));
//	if(lst/tmp==0) putchar('.');
	lst%=tmp;
	arr[0]=lst;
	while(1){
		arr[len]=(arr[len-1]*10)%tmp;
		if(arr[len]==arr[0])
			break;
		len++;
	}
}
//		putchar('(');
//		for(int i=0;i<len;i++)
//			printf("%d",arr[i]*10/tmp);
//		putchar(')');
	}
int main(){
	a=1;
	scanf("%d",&b);
	solve();
	printf("%d",len);
}

