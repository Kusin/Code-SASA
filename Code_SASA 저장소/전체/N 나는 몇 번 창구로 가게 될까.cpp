#include<iostream> //�������� ��� 
int m,n,t,cnt,num;
int main(){
	std::cin>>m>>n;
	while(cnt<=n){
		for(int i=1;i<=m;i++){
			if(t%i==0){
				cnt++;
				num=i;
			}
			if(cnt==n+1)
				break;
		}
		t++;
	}
	std::cout<<num;
}
