#include<iostream>
#include<string>
using namespace std;
string str;
int main(){
	int n;
	cin>>n;
	cin.ignore(256,'\n');
	getline(cin,str);
	cout<<n<<'\n'<<str;
}
