#include<stdio.h>
#include<stack>
using namespace std;
bool isop(char x){
	return x=='+'||x=='-'||x=='*'||x=='/';
}
int main(){
	int len;
	char c[51],op[5]={'*','/','+','-'};
	stack<int> st;
	scanf("%s",c);
	for(len=0;c[len];len++);
	for(int i=0;i<len;i++){
		if(isop(c[i])){
			int x;
			for(x=0;x<4;x++)
				if(op[x]==c[i])
					break;
			while(!st.empty()&&st.top()<x) printf("%c",op[st.top()]),st.pop();
			st.push(x);
		}
		else
			putchar(c[i]);
	}
	while(!st.empty())
		printf("%c",op[st.top()]),st.pop();
}
