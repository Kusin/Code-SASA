#include <stdio.h>

int n, a[110];

void swap(int x, int y) {
    int t = a[x];
    a[x] = a[y];
    a[y] = t;
}

int big(int e) {
    int t = 0;
    for(int i=1; i<=e; i++)
        if(a[t] < a[i]) t=i;
        
    return t;
}
void sort(int e){
	if(!e)
		return; 
	 swap(e,big(e));
	 sort(e-1);
}
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);

    sort(n-1);

    for(int i=0; i<n; i++)
        printf("%d ", a[i]);

    return 0;
}


