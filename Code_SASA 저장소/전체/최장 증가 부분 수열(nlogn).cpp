#include<iostream> // ������Ű ���� ���� �κ� ���� 3.2 
using namespace std;
int n,a[1001],dpA[1001],dpD[1001]; //dpD[i]�� i�� ������ ������ ������ ���� �� �����κм����� ���� 
int idx,tmp;
int lower_bound(int s,int e,int k){
	while(s<e){
		int m=(s+e)/2;
		if(dpA[m]>=k)
			e=m;
		else
			s=m+1;
	}
	return e;
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		if(dpA[idx]<a[i])
			dpA[++idx]=a[i],dpD[idx]=idx;
		else
			tmp=lower_bound(0,idx,a[i]),dpA[tmp]=a[i];	
	cout<<dpD[idx];
}

