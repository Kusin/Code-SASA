#include<iostream>
using namespace std;
int n,a[101],k;
void lb_(int k){
	int x=0,y=n;
	while(x<y){
		int m=(x+y)/2;
		cout<<a[m]<<' ';
		if(a[m]<k)
			x=m+1;
		else
			y=m;
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	cin>>k;
	lb_(k);
} 
