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
    //�ܹ��� ����� �ֹ��� �ð� ������� ť�� �ֱ� 
    for(int i=0;i<n;i++) { 
        scanf("%d %d",&t1, &h1);
        while(t2<=t1) {
            enQue(5);
            t2+=10;
        }
        enQue(-h1);
    }
    // ť�� �ִ� �۾��� ������� ó��
    int h=0;
    while(h1 = deQue()) {
        if(h1+h>=0) {
            h+=h1;
            if(h1<0) sum+=-h1;
        }
    }
    printf("%d",sum);
} 
