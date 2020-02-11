#include<stdio.h>
#include<stack>
#include<string.h>
using namespace std;
stack<char> st;
char x[200020];
int len;
int main(){
    scanf("%s",x);
    len=strlen(x);
    int ans=len;
    for(int i=0;i<len;i++){
        if(x[i]=='S')
        st.push('S');
        else if(!st.empty()&&x[i]=='A')
        st.pop(),ans-=2;
    }
    printf("%d",ans);
}
