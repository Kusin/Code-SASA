#include<iostream>
#include<string>
#include<map>
using namespace std;
int n,m,cnt;
map<string,int> ku;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	cin.ignore(256,'\n');
	for(int i=0;i<n;i++){
		string str;
		getline(cin,str); 
		ku[str]=1;
	}
	for(int i=0;i<m;i++){
		string str;
		getline(cin,str);
		if(ku.count(str)==0)
			cout<<str<<'\n';
	}
	return 0;
}
