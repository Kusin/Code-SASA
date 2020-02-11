#include <stdio.h>

int n, k;
int arr[5000];
int base;
int max;

void setBase(){
	base=1;
	while(base<n) base*=2;
}
void setTree(){
	for(int i=base-1;i>=1;i--)
		arr[i]=arr[2*i]>arr[2*i+1]?arr[2*i]:arr[2*i+1];
}
void update(int a, int b){
	a=a+base-1;
	arr[a]=b;
	while(a>1){
		a>>=1;
		arr[a]=arr[2*a]>arr[2*a+1]?arr[2*a]:arr[2*a+1];
	}
}
void submax(int a, int b){
	while(a<b){
		if(a%2==1){
			max=arr[a]>max?arr[a]:max;
			a++;
		}
		if(b%2==0){
			max=arr[b]>max?arr[b]:max;
			b--;
		}
		a>>=1;
		b>>=1;
	}
	if(a==b)
		max=arr[a]>max?arr[a]:max;
}

int main() {
    scanf("%d%d", &n, &k);

    setBase();

    for(int i=base; i<base+n; i++)
        scanf("%d", &arr[i]);

    setTree();

    for(int i=0; i<k; i++) {
        int c, a, b;
        scanf("%d%d%d", &c, &a, &b);
        if(c == 1) {
            max = -987654321;
            submax(a+base-1, b+base-1);
            printf("%d ", max);
        }
        else update(a, b);
    }
    return 0;
}
