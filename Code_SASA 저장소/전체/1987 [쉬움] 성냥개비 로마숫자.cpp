#include<stdio.h>
int n,i,cnt[7],arr[7]={1,2,2,2,2,3,4},ans;
int main(){
	scanf("%d",&n);
	cnt[6]+=n/1000;
	n%=1000;
	switch(n/100){
		case 9:cnt[6]++; cnt[4]++; break;
		case 8: case 7: case 6: case 5: cnt[5]++; cnt[4]+=(n/100)-5; break;
		case 4: cnt[5]++; cnt[4]++; break;
		default: cnt[4]+=(n/100);
	} 
	n%=100;
	switch(n/10){
		case 9: cnt[4]++; cnt[2]++; break;
		case 8: case 7: case 6: case 5: cnt[3]++; cnt[2]+=(n/10)-5; break;
		case 4: cnt[3]++; cnt[2]++; break;
		default: cnt[2]+=(n/10);
	}
	n%=10;
	switch(n){
		case 9: cnt[2]++; cnt[0]++; break;
		case 8: case 7: case 6: case 5: cnt[1]++; cnt[0]+=n-5; break;
		case 4: cnt[1]++; cnt[0]++; break;
		default: cnt[0]+=n;
	}
	for(i=0;i<7;i++)
		ans+=arr[i]*cnt[i];
	printf("%d",ans);
}
