#include<stdio.h>
#include<iostream>
int n,arr[100010];
int R(){
	char now=getchar_unlocked();
	int sum=0;
	while(now<=32) now=getchar_unlocked();
	while(now>=48){
		sum=sum*10+now-48;
		now=getchar_unlocked();
	}
	return sum;
} 
int main(){
	std::ios::sync_with_stdio(false);
	n=R(); 
	for(int i=0,k;i<n;i++){
		k=R();
		arr[k]++;
	}
	for(int i=0;i<=100000;i++){
		int x=arr[i];
		for(int j=0;j<x;j++)
			std::cout<<i<<" ";
	}
}
