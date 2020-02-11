#include<stdio.h>
#include<vector>
#include<assert.h>
using namespace std;
vector<int> v;
char str[40];
int start_[20],end_[20]; //괄호 위치 표시 -> ( :start, ) :end 
int chg[40],rev_chg[20]; //음표 환산  
void read(){
	int len=0;
	for(;str[len]!='\0';len++);
	int readStart=0,num=0;
	for(int i=0;i<=len;i++){
		if(str[i]>='0'&&str[i]<='9'){
			if(readStart){
				num = num*10 + str[i]-'0';
			}
			else{
				num = str[i]-'0';
				readStart=1;
			}
		}
		else{
			if(readStart){
				v.push_back(num);
				readStart=0;
			}
		}
	}
}
void init(){
	chg[8]=4, chg[12]=6, chg[16]=2, chg[24]=3, chg[32]=1;
	rev_chg[4]=8, rev_chg[6]=12, rev_chg[2]=16, rev_chg[3]=24, rev_chg[1]=32;
}
int main(){
	scanf("%[^\n]s",str);
	read();
	init();
	int sum=0,ans[50],cnt=0,chk=0; 
	for(vector<int>::iterator i=v.begin();i!=v.end();i++){ //시험 삼아 써본 것 
		*i = chg [*i];
		chk+=*i;
	}
	assert(chk==32); // 1마디의 길이가 맞는지 확인  
	for(vector<int>::iterator i=v.begin();i!=v.end();i++){
		if(sum==0)
			start_[cnt]=1;
		if(sum+*i<8)
			sum+=*i,ans[cnt++]=*i;
		else if(sum+*i==8){
			end_[cnt]=1;
			ans[cnt++]=*i;
			sum=0;
		}
		else{
			end_[cnt]=1;
			*i = *i - (8-sum);
			ans[cnt++]=8-sum;
			sum=0;
			i--;
		}
	}
	for(int i=0;i<cnt;i++){
		if(i>0&&end_[i-1]) printf(" ");
		if(start_[i])printf("(");
		printf("%d",rev_chg[ans[i]]);
		if(!end_[i]) printf(" ");
		else printf(")");
	}
} 
