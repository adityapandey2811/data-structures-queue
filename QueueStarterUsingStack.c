#include<stdio.h>
#include<stdlib.h>
typedef struct que{
    int *arr,front,rear,len;
}queue;
queue* create(queue *newq){
    int n;
    queue *temp = newq;
    temp = (queue*)malloc(sizeof(queue));
    printf("Enter len: ");
    scanf("%d",&n);
    temp->arr = (int*)malloc(sizeof(int)*(n+1));
    temp->len = n+1;
    temp->front = 0;
    temp->rear = 0;
    return temp;
}
int isEmpty(queue *newq){
    if(newq->front == newq->rear)
        return 1;
    return 0;
}
int isFull(queue *newq){
    if((newq->front+1)%newq->len == newq->rear)
        return 1;
    return 0;
}
void display(queue *newq){
    int i,k;
    i = newq->rear;
    k = newq->front;
    for(i;i!=k;i=(i+1)%newq->len){
        printf("%d ",newq->arr[i]);
    }
    printf("\n");
}
queue* enque(queue *newq){
    int n;
    queue *temp = newq;
    if(temp == NULL){
        temp = create(temp);
    }
    if(isFull(temp)){
        printf("Queue Full\n");
        return temp;
    }
    printf("Enter: ");
    scanf("%d",&temp->arr[temp->front]);
    temp->front = (temp->front+1)%temp->len;
    return temp;
}
int deque(queue *newq){
    int n;
    queue *temp = newq;
    if(isEmpty(temp)){
        printf("Queue Empty\n");
        return 0;
    }
    else{
        n = temp->arr[temp->rear];
        printf("%d Dequed\n",temp->arr[temp->rear]);
        temp->rear = (temp->rear+1)%temp->len;
        return n;
    }
    return 0;
}
int main(){
    int i=0,j,k;
    queue *newq = NULL;
    printf("1. Enque\n2. Deque\n3. Display\n");
    while(k!=-1){
        printf("Enter Index: ");
        scanf("%d",&k);
        if(k==1){
            newq = enque(newq);
        }
        else if(k==2){
            j = deque(newq);
        }
        // else if(k==3){
        //     isEmpty(newq);
        // }
        // else if(k==4){
        //     isFull(newq);
        // }
        else if(k==3){
            display(newq);
        }
    }
}
