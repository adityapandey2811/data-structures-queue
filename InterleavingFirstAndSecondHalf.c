#include<stdio.h>
#include<stdlib.h>
#include"q.h"
#include"ss.h"
int main(){
    queue *q7 = NULL;
    stack *s3 = NULL;
    int i,n;
    for(i=11;i<=20;i++)
        enqueue(&q7,i);
        n = size(q7);
    printf("Size: %d\n",n);
    for(i=0;i<n/2;i++)
        pushI(&s3,deque(&q7));
    while(!isEmptys(s3))
        enqueue(&q7,popI(&s3));
    for(i=0;i<n/2;i++)
        enqueue(&q7,deque(&q7));
    for(i=0;i<n/2;i++)
        pushI(&s3,deque(&q7));
    while(!isEmptys(s3)){
        enqueue(&q7,popI(&s3));
        enqueue(&q7,deque(&q7));
    }
    displayq(q7);
}
