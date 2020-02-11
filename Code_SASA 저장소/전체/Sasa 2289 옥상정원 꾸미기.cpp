#include<stdio.h>
#include<vector>
#include<utility> 
using namespace std;
int n,cnt[80000];
typedef pair<int,int> pr2;
int main(){
	scanf("%d",&n);
	int arr[80000];
	for(int i=0;i<n;i++) scanf("%d",arr+i);
	vector<pr2 > v;
	v.push_back(pr2(1<<30,n));
	for(int i=n-1;i>=0;i--){
		while(v.back().first<arr[i]) v.pop_back();
		cnt[i]=v.back().second-i-1;
		v.push_back(pr2(arr[i],i));
	}
	for(int i=0;i<n;i++)
		printf("%d\n",cnt[i]);
}
