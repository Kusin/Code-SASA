#include <stdio.h>
#define MAX 200

int front=-1;
int rear=0;
int q[MAX];

void enQue(int d) {
	while(front<0)
		front++;
	if(rear<MAX)
		q[rear++]=d;
}

int deQue() {
    int d=0;
    if(front>=0&&front<rear)
        d=q[front++];
    return d;
}

int main() {
    int n,t1,t2,h1;
    int sum=0;
    t2=10;
    scanf("%d",&n);
    //햄버거 생산과 주문을 시간 순서대로 큐에 넣기 
    for(int i=0;i<n;i++) { 
        scanf("%d %d",&t1, &h1);
        while(t2<=t1) {
            enQue(5);
            t2+=10;
        }
        enQue(-h1);
    }
    // 큐에 있는 작업을 순서대로 처리
    int h=0;
    while(h1 = deQue()) {
        if(h1+h>=0) {
            h+=h1;
            if(h1<0) sum+=-h1;
        }
    }
    printf("%d",sum);
} 
