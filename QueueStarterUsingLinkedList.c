#include<stdio.h>
#include<stdlib.h>
typedef struct n{
    int data;
    struct n *next;
}node;
typedef struct q{
    node *front,*rear;
}queue;
void display(queue *temp){
    node *d = NULL;
    if(temp != NULL)
        d = temp->front;
    while(d!=NULL){
        printf("%d ",d->data);
        d=d->next;
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
int main(){
    int i,k;
    queue *head = NULL;
    printf("1. Enque\n2. Deque\n3. Display\n");
    while(i!=-1){
        printf("Enter: ");
        scanf("%d",&i);
        if(i==1){
            enque(&head);
        }
        else if(i==2){
            k = deque(&head);
            printf("Dequed = %d",k);
        }
        else if(i==3){
            display(head);
        }
    }
}
