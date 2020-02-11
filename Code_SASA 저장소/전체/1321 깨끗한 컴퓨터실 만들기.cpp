#include<iostream>
#include<algorithm>
using namespace std;
struct A{
	int num,ord,ord2;
}E[101];
bool cmp1(A a1,A a2){
	return a1.num>a2.num;
}
bool cmp2(A a1,A a2){
	return a1.ord<a2.ord;
}
int n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
			cin>>E[i].num;
			E[i].ord=i;
		}
	sort(E+1,E+n+1,cmp1);
	for(int i=1;i<=n;i++)
		E[i].ord2=i;
	for(int i=2;i<=n;i++)
		if(E[i-1].num==E[i].num)
			E[i].ord2=E[i-1].ord2;
	sort(E+1,E+n+1,cmp2);
	for(int i=1;i<=n;i++)
		printf("%d\n",E[i].ord2);
}
