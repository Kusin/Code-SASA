#include<iostream>
using namespace std;
int n;
int a[1001],d[1001],m[1001]; //d[i]�� i�� ������ ������ ������ ���� �� �����κм����� ���� 
int max(int k){
	int t=0;
	for(int i=0;i<k;i++)
		if((a[i]<=a[k])&&(d[i]>t))
			t=d[i];
	return t;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		d[i]=max(i)+1;
	a[n+1]=(1LL<<31)-1;
	printf("%d\n",max(n+1));
}
