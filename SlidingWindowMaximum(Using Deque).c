#include<stdio.h>
#include<stdlib.h>
#include"dqe.h"
void maxSlidingWindow(int a[], int n, int w, int *b){
    deque *q1 = NULL;
    int i=0;
    for(i=0;i<w;i++){
        while(q1 && a[i] >= a[q1->rear->data])
            r_deque(&q1);
        r_enque(&q1,i);
    }
    for(i = w;i<n;i++){
        *b = a[q1->front->data];
        while(q1 && a[i] >= a[q1->rear->data])
            r_deque(&q1);
        while(q1 && q1->front->data <= i-w)
            f_deque(&q1);
        r_enque(&q1,i);
        b++;
    }
    *b = q1->front->data;
}
int main(){
    int a[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = sizeof(a)/sizeof(a[0]);
    int w = 3;
    int b[n-(w-1)];
    maxSlidingWindow(a,n,w,b);
    for(int i=0;i<n-(w-1);i++)
        printf("%d ",b[i]);
    return 0;
}
//1 3 -1 -3 5 3 6 7