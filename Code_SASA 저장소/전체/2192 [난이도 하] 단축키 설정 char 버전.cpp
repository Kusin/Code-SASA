#include<stdio.h> //string은 Code SASA에서 쓰지 말자.
#include<string.h>
#include<map>
using namespace std;
map<char,int> d;
char str[1010][100];
int n;
char atoA(char x){
    if(x>='a'&&x<='z')
        return (x+'A'-'a');
    else
        return x;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        bool flag=1;
        scanf(" %[^\n]s",str[i]);
        for(int j=0;j<strlen(str[i]);j++){
            char k=str[i][j];
            if(k>'z'||k<'A'||(k>'Z'&&k<'a')) continue;
            k=atoA(k);
            if(d.count(k)>0) continue;
            else {
                d[k]=1; flag=0; printf("%c",k);
                break;
            }
        }
        if(flag) printf("YOU MUST SET ANOTHER KEY!");
        puts("");
    }
}
