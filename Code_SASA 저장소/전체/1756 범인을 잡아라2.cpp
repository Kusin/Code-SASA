#include<stdio.h>
#include<algorithm>
using namespace std;
int a[10];
bool comp(int x,int y){
return x>y;
}
int main(){
	for(int i=0;i<10;i++)
	scanf("%d",&a[i]);
sort(a,a+10,comp);
printf("%d",a[2]);
return 0;
} //퀵 정렬 구현하기 ; 
