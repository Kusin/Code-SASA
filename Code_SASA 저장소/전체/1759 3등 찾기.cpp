#include<stdio.h>
#include<algorithm>
#include<utility> 
using namespace std;
typedef struct student{
  char name[30];
  int point;
}SS;
bool comp(SS a,SS b){
   return a.point>b.point;
}
char a[20];
int main(){
  int n;
  scanf("%d",&n);
  SS a[51];
		for(int i=1;i<=n;i++){
		scanf("%s%d",a[i].name,&a[i].point);
	}
	sort(a+1,a+n+1,comp);
	printf("%s",a[3].name);
	return 0; 
}
