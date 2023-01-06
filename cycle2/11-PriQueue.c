#include<stdio.h>
#include<stdlib.h>
int front=-1;
int rear=-1;
int q[2][20];

void display(){
    printf("\n");
    for(int i=0;i<2;i++){
        for(int j=front;j<=rear;j++)
            printf("%d\t",q[i][j]);
        printf("\n");
    }
    printf("\n") ;
}
void sort(int n){
    int n1=rear-front+1;
    int temp1;
    int temp2;
    for(int i=0;i<n1-1;i++)
        for(int j=0;j<n1-i-1;j++)
            if(q[1][j]<q[1][j+1]){
                temp1=q[1][j];
                q[1][j]=q[1][j+1];
                q[1][j+1]=temp1;
                temp2=q[0][j];
                q[0][j]=q[0][j+1];
                q[0][j+1]=temp2;
            }
}
void enqueue(int n){
    if(rear==n-1)
        printf("Queue is full\n");
    else if(front==-1 && rear==-1){
        front= rear = 0;
        printf("Enter the element : ");
        scanf("%d",&q[0][rear]);
        printf("Enter the priority : ");
        scanf("%d",&q[1][rear]);
        sort(n);
        display();
    }else{
        rear++;
        printf("Enter the element : ");
        scanf("%d",&q[0][rear]);
        printf("Enter the priority : ");
        scanf("%d",&q[1][rear]);
        
        sort(n);
        display();
    }
}
void dequeue(){
    if(front==-1 && rear==-1)
        printf("Queue is empty\n");
    else if(front==0 && rear==0){
        front=-1;
        rear=-1;
        display();
    }else{
        front++;
        display();
    }
}
void main(){
    int n,c;
    printf("Enter the size of queue : ");
    scanf("%d",&n);
    while(1){
        printf("Enter \n1. Enqueue\t2. Dequeue\t3. display\t4. exit\n >> ");
        scanf("%d",&c);
        switch(c){
            case 1:
                enqueue(n);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
        }
    }
}