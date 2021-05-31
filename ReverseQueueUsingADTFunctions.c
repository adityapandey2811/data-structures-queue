#include<stdio.h>
#include<stdlib.h>
#include"ss.h"
#include"q.h"
int main(){
    int i = 0,j,k,n;
    stack *top = NULL;
    queue *head = NULL;
    for(i=0;i<6;i++)
        enqueue(&head,i);
    printf("Queue before: ");
    displayq(head);
    for(i=0;i<6;i++){
        n = deque(&head);
        pushI(&top,n);
    }
    for(i=0;i<6;i++){
        n = popI(&top);
        enqueue(&head,n);
    }
    printf("\nQueue after: ");
    displayq(head);
    return 0;
}
