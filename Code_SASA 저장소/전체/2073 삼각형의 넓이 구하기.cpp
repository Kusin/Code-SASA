#include<stdio.h>
#include<math.h>
int a,b,h;
bool chk(float a,float b,float c){
	return !(a+b<=c&&b+c<=a&&c+a<=b);
}
int main(){
	scanf("%d%d%d",&a,&b,&h);
	if(a>h&&b>h){
	float c=sqrt(a*a-h*h)+sqrt(b*b-h*h);
	float area=c*h/2;
	if(chk((float)a,float(b),c)){
		if(a==b||b==c||c==a)
			printf("%d %.1f",(int)c,area);
		else
			printf("%.1f",area);
	}
	else
		printf("Not Triangle");
	}
	else
		printf("Not Triangle");
}
