#ifndef queue_h
#define queue_h

#include<stdio.h>
#include<stdlib.h>
typedef struct n{
    int data;
    struct n *next;
}node;
typedef struct q{
    node *front,*rear;
}queue;
void displayq(queue *temp){
    node *d = NULL;
    if(temp != NULL)
        d = temp->front;
    while(d!=NULL){
        printf("%d ",d->data);
        d=d->next;
    }
}
void enqueue(queue **head, int n){
    queue *temp = *head,*newnode = NULL;
    newnode = (queue*)malloc(sizeof(queue));
    newnode->rear = (node*)malloc(sizeof(node));
    newnode->rear->data = n;
    newnode->rear->next = NULL;
    if(temp == NULL){
        newnode->front = newnode->rear;
        (*head) = newnode;
    }
    else{
        temp->rear->next = newnode->rear;
        temp = newnode;
        (*head)->rear = newnode->rear;
    }
}
void enque(queue **head){
    int n;
    queue *temp = *head,*newnode = NULL;
    printf("Enter data: ");
    scanf("%d",&n);
    newnode = (queue*)malloc(sizeof(queue));
    newnode->rear = (node*)malloc(sizeof(node));
    newnode->rear->data = n;
    newnode->rear->next = NULL;
    if(temp == NULL){
        newnode->front = newnode->rear;
        (*head) = newnode;
    }
    else{
        temp->rear->next = newnode->rear;
        temp = newnode;
        (*head)->rear = newnode->rear;
    }
}
int deque(queue **head){
    node *temp = NULL;
    if((*head) != NULL)
        temp = (*head)->front;
    int n;
    if(temp == NULL){
        printf("Queue Empty\n");
        return 0;
    }
    else{
        (*head)->front = (*head)->front->next;
        if((*head)->front == NULL)
            (*head) = NULL;
        n = temp->data;
        free(temp);
        return n;
    }
}

#endif
