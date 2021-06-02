#include<stdio.h>
#include<stdlib.h>
#include"q.h"
#include"ss.h"
int main(){
    int i,k;
    queue *q7 = NULL;
    stack *s3 = NULL;
    for(i=1;i<=10;i++)
        enqueue(&q7,i);
    displayq(q7);
    printf("\nK: ");
    scanf("%d",&k);
    for(i=k;i>0;i--)
        pushI(&s3,deque(&q7));
    while(!isEmptys(s3))
        enqueue(&q7,popI(&s3));
    for(i=0;i<size(q7)-k;i++){
        enqueue(&q7,deque(&q7));
    }
    displayq(q7);
}
