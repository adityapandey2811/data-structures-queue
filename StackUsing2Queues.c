#include<stdio.h>
#include<stdlib.h>
#include"q.h"
typedef struct s{
    queue *q1;
    queue *q2;
}stack;
void push(stack **top, int n){
    stack *head = *top;
    if(head == NULL){
        head = (stack*)malloc(sizeof(stack));
        head->q1 = head->q2 = NULL;
    }
    if(isEmpty(head->q1)){
        enqueue(&head->q2,n);
    }
    else{
        enqueue(&head->q1,n);
    }
    (*top) = head;
}
int pop(stack **top){
    int n;
    node *temp = NULL;
    stack *head = *top;
    if(head == NULL || (head->q1 == NULL && head->q2 == NULL)){
        printf("Stack Empty\n");
        return 0;
    }
    if(isEmpty(head->q1)){
        while(head->q2->rear != head->q2->front){
            n = deque(&head->q2);
            enqueue(&head->q1,n);
        }
        n = deque(&head->q2);
    }
    else{
        while(head->q1->rear != head->q1->front){
            n = deque(&head->q1);
            enqueue(&head->q2,n);
        }
        n = deque(&head->q1);
    }
    return n;
}
int main(){
    int i,n;
    stack *top = NULL;
    printf("1. Push\n2. Pop\n");
    while(i!=-1){
        printf("Enter: ");
        scanf("%d",&i);
        if(i==1){
            printf("Data: ");
            scanf("%d",&n);
            push(&top,n);
        }
        else if(i==2){
            n = pop(&top);
            printf("Pop - %d\n",n);
        }
    }
    return 0;
}
