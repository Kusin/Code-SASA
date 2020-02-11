#include<iostream>
#include<algorithm>
using namespace std;
int n,arr[200],v[200];
int main(){
	cin>>n;
	for(int i=1,x;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1);
	int m=10000;
	for(int i=2;i<=n;i++){
		v[i]=arr[i]-arr[i-1];
		if(v[i]<m)
			m=v[i];
	}
	for(int i=2;i<=n;i++){
		if(v[i]==m)
			cout<<arr[i-1]<<','<<arr[i]<<endl;
	}
	return 0;
}
