#include<stdio.h>
#include<algorithm>
using namespace std;
int n;
struct go{
	double walk,run;
	double a,b;
}S[110];
bool cmp(go a1,go a2){
	return a1.a<a2.a;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf %lf",&S[i].walk,&S[i].run);
		S[i].a=(double)10.0/S[i].run;
		S[i].b=(double)1.0/S[i].walk - (double)1.0/S[i].run;
	}
	sort(S+1,S+n,cmp);
	long double ans=0,mw=-1;
	if(n>2){
	for(double i=0.000001;i<=(double)10.0;i+=0.000001){
		long double x=S[n].a+i*S[n].b,t=(long double)5.0;
		bool flag=0;
		for(int j=1;j<n;j++){
			long double k=S[j].a+i*S[j].b;
			if(k<x){
				flag=1;
				break;
			}
			if(k<t) t=k;
		}
		if(flag) continue;
		long double y= t-x;
		if(y>mw && i>ans+0.0000005){
			mw=y;
			ans=i;
		}
	}
	}else{
		for(double i=0.000001;i<=(double)10.0;i+=0.000001){
		long double x=S[n].a+i*S[n].b;
		if(x>mw){
			mw=x;
			ans=i;
		}
		}
	}
	printf("%lf %lf",(double)ans,10-(double)ans);
} 
