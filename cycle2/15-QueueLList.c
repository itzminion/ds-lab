#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};
struct node *front;
struct node *rear;
struct node *q_head;
struct node *new;
struct node *ptr;

void enqueue(int value){
    new=(struct node *)malloc(sizeof(struct node));
    if(q_head->link==NULL){
        front=new;
        rear=new;
        q_head->link=new;
        rear->data=value;
        rear->link=NULL;
    }else{
        rear->link=new;
        rear=new;
        rear->data=value;
        rear->link=NULL;
    }
}
void dequeue(){
    int item;
    if(q_head->link==NULL){
        printf("Queue is empty\n");
    }else if(q_head->link->link==NULL){
        item=front->data;
        q_head->link=NULL;
        front=NULL;
        rear=NULL;
        printf("Dequeued : %d\n",item);
    }else{
        item=front->data;
        q_head->link=front->link;
        front=front->link;
        printf("Dequeued : %d\n",item);
    }
}
void display(){
    ptr=q_head->link;
    printf("\n");
    if(ptr==NULL)
        printf("Queue is empty\n");
    else{
        while(ptr!=NULL){
            printf("->%d",ptr->data);
            ptr=ptr->link;
        }
        printf("\n");
    }
}
void main(){
    front=(struct node *)malloc(sizeof(struct node));
    rear=(struct node *)malloc(sizeof(struct node));
    q_head=(struct node *)malloc(sizeof(struct node));
    front=NULL;
    rear=NULL;
    q_head->link=NULL;
    int value,ch;
    while(1){
        printf("\n\nEnter 1. Insert \t2. Dequeue \t3. Display \t4. Exit\n>> " ) ;
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter value : ");
                scanf("%d",&value);
                enqueue(value);
                display();break;
            case 2:
                dequeue();       
                display();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
        }
    }
}