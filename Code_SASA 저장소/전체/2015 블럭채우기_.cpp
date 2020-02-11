#include<iostream>
using namespace std;
int n;
int memo[10001]={1,1,3};
int cnt(int k){
	if(memo[k])
		return memo[k];
	memo[k]=(cnt(k-1)+2*cnt(k-2))%100007;
	return memo[k];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	cout<<cnt(n);
}
