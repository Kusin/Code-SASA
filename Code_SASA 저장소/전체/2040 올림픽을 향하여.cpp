#include<iostream>
#include<algorithm>
using namespace std;
int n,k,rec[100];
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>rec[i];
	cin>>k;
	sort(rec,rec+n);
	for(int i=0;i<k;i++,puts(""))
		for(int j=0;j<=i;j++)
			cout<<rec[j]<<" ";
}
