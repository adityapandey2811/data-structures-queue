#include<stdio.h>
#include<stdlib.h>
#include"ss.h"
typedef struct que{
    stack *s1;
    stack *s2;
}queue;
void enque(queue **head){
    int n;
    queue *temp = *head;
    printf("Enter data: ");
    scanf("%d",&n);
    if(temp == NULL){
        temp = (queue*)malloc(sizeof(queue));
        temp->s2 = temp->s1 = NULL;
    }
    pushI(&(temp->s1),n);
    (*head) = temp;
}
int deque(queue **head){
    int n;
    if((*head) == NULL){
        printf("Empty");
        return 0;
    }
    if(!isEmpty((*head)->s2)){
        n = popI(&(*head)->s2);
        if((*head)->s1 == NULL && (*head)->s2 == NULL)
            (*head) = NULL;
        return n;
    }
    else{
        while(!isEmpty((*head)->s1)){
            n = popI(&(*head)->s1);
            pushI(&(*head)->s2,n);
        }
        n = popI(&(*head)->s2);
        if((*head)->s1 == NULL && (*head)->s2 == NULL)
            (*head) = NULL;
        return n;
    }
}
int main(){
    int i=0,j,k,n;
    queue *head = NULL;
    printf("1. Enque\n2. Deque\n");
    while(i!=-1){
        printf("Enter: ");
        scanf("%d",&i);
        if(i==1)
            enque(&head);
        else if(i==2){
            n = deque(&head);
            printf("Dequed - %d\n",n);
        }
        else if(i==3 && head!=NULL){
            displayI(head->s1);
            displayI(head->s2);
        }
    }
    return 0;
}
