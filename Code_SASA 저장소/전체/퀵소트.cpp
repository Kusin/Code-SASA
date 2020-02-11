#include <stdio.h>

int n, a[100010];
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
inline void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int*a, int start, int end){
	int p=start,l=start+1,r=end;
	while(l<=r){
			while(a[l]<=a[p]&&l<=end)l++;
			while(a[r]>=a[p]&&r>=start+1)r--;
			if(l<r) swap(a+l,a+r);
	}
	swap(a+p,a+r);
	return r;
}


void quick(int a[], int p, int r) {
    if(p>=r) return;
    int q = partition(a, p, r);  //
    quick(a, p, q-1);
    quick(a, q+1, r);
}

int main() {
    n=R();
    for(int i=0; i<n; i++)
       	a[i]=R();

    quick(a, 0, n-1);

    for(int i=0; i<n; i++)
        printf("%d\n", a[i]);

    return 0;
}
