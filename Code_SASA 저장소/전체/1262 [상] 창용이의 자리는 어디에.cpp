#include<stdio.h>
#include<queue>
using namespace std;
struct S{
	int h,a,b;
}arr[6]; 
struct cmp{
	bool operator()(S *s1,S *s2){
		return s1->h > s2->h;
	}
};
priority_queue<S,vector<S*>,cmp> pq;
int main(){
	printf("test");
}
