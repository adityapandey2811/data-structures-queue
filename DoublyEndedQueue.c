#include<stdio.h>
#include<stdlib.h>
typedef struct n{
    int data;
    struct n *next;
}node;
typedef struct dq{
    node *front,*rear;
}deque;
void display(deque *q7){
    node *temp;
    if(q7 == NULL)
        return;
    for(temp = q7->front; temp != NULL; temp = temp->next){
        printf("%d ",temp->data);
    }
}
//merge enque functions
void f_enque(deque **q7){
    node *spare = NULL;
    int n;
    if((*q7) == NULL){
        (*q7) = (deque*)malloc(sizeof(deque));
        (*q7)->front = (*q7)->rear = NULL;
    }
    printf("Enter something: ");
    scanf("%d",&n);
    spare = (node*)malloc(sizeof(node));
    spare->data = n;
    spare->next = NULL;
    if((*q7)->front == NULL){
        (*q7)->front = (*q7)->rear = spare;
    }
    else{
        spare->next = (*q7)->front;
        (*q7)->front = spare;
    }
}
int f_deque(deque **q7){
    int n;
    node *temp = NULL;
    if((*q7) == NULL || (*q7)->front == NULL){
        printf("Deeue Empty\n");
        return 0;
    }
    temp = (*q7)->front;
    n = temp->data;
    (*q7)->front = (*q7)->front->next;
    free(temp);
    if((*q7)->front == NULL)
        (*q7) = NULL;
        return n;
}
//merge enque functions
void r_enque(deque **q7){
    node *spare = NULL;
    int n;
    if((*q7) == NULL){
        (*q7) = (deque*)malloc(sizeof(deque));
        (*q7)->front = (*q7)->rear = NULL;
    }
    spare = (node*)malloc(sizeof(node));
    printf("Enter something: ");
    scanf("%d",&n);
    spare->data = n;
    spare->next = NULL;
    if((*q7)->front == NULL){
        (*q7)->front = (*q7)->rear = spare;
    }
    else{
        (*q7)->rear->next = spare;
        (*q7)->rear = spare;
    }
}
int r_deque(deque **q7){
    node *temp = NULL;
    int n;
    if((*q7) == NULL || (*q7)->front == NULL){
        printf("Deque Empty\n");
        return 0;
    }
    temp = (*q7)->front;
    if(temp->next != NULL)
        for(temp; temp->next != (*q7)->rear; temp = temp->next);
    else{
        n = temp->data;
        free(temp);
        (*q7) = NULL;
        return n; 
    }
    (*q7)->rear = temp;
    temp = temp->next;
    n = temp->data;
    free(temp);
    (*q7)->rear->next = NULL;
    return n;
}
int main(){
    int i,n;
    deque *q7 = NULL;
    printf("1. F_enque\n2. F_deque\n3. R_enque\n4. R_deque\n5. Display\n");
    while(i!=-1){
        printf("Enter index: ");
        scanf("%d",&i);
        if(i==1){
            f_enque(&q7);
        }
        else if(i==2){
            n = f_deque(&q7);
            printf("Front Deque - %d\n",n);
        }
        else if(i==3){
            r_enque(&q7);
        }
        else if(i==4){
            n = r_deque(&q7);
            printf("Rear Deque - %d\n",n);
        }
        else if(i==5){
            display(q7);
        }
    }
    return 0;
}
