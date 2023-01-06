#include<stdio.h>
#include<stdlib.h>
struct NODE{
    int data ;
    struct NODE *next ;
};

struct NODE *HEADER ;
void display(){
    struct NODE *ptr = HEADER ;
    if ( ptr->next == NULL ){
        return;
    }
    printf(" => ") ;
    while ( (ptr->next != NULL) ){
        ptr = ptr->next ;
        printf("%d ",ptr->data) ;
    }
}
void push(){
    struct NODE *new = (struct NODE*)malloc(sizeof(struct NODE)) ;
    if ( new == NULL ){
        printf("Insertion Not Possible ! ") ;
        return ;
    }
    int value ;
    printf("Enter value : ") ;
    scanf("%d", &value) ;
    new->data = value ;
    new->next = HEADER -> next ;
    HEADER->next = new ;
    display() ;
}
void pop(){
    int value ;
    if (HEADER->next == NULL){
        printf("\nStack Empty \n") ;
        return ;
    }
    struct NODE *ptr ;
    ptr = HEADER->next ;
    value = ptr->data ;
    printf("%d ", value) ;
    ptr = ptr->next ;
    HEADER->next = ptr ;
    display() ;
}
void main(){
    HEADER = (struct NODE*)malloc(sizeof(struct NODE)) ;
    HEADER-> next = NULL ;
    int choice ;
    do{
        printf("\n\nEnter 1. Push \t2. Pop \t3. Display\t4. Exit\n>> ") ;   
        scanf("%d",&choice);
        switch(choice){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("EXIT POINT \n");
                break;
            default:
                printf ("Invalid Entry ! ");
        }
    }while(choice!=4);
}