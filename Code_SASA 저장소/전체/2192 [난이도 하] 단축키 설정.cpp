#include<iostream> //채점 제대로 안됨.. getline(cin,str) 할 때 문제가 있는 듯. 
#include<string.h>
#include<string>
#include<map>
using namespace std;
map<char,int> d;
int n;
char atoA(char x){
    if(x>='a'&&x<='z')
        return (x+'A'-'a');
    else
        return x;
}
int main(){
    scanf("%d",&n);
    getchar();
    string str[1010];
    for(int i=0;i<n;i++){
        bool flag=1;
        getline(cin,str[i]);
        for(int j=0;j<str[i].length();j++){
            char k=str[i][j];
            if(k>'z'||k<'A'||(k>'Z'&&k<'a')) continue;
            k=atoA(k);
            if(d.count(k)>0) continue;
            else {
                d[k]=1; flag=0; printf("%c ",k);
                break;
            }
        }
        if(flag) printf("YOU MUST SET ANOTHER KEY! ");
        if(i<n-1) puts("");
    }
}
