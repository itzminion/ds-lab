#include<stdio.h>
int stack[100];
int queue[100];
int size ;
int TOP = -1 ;
int FRONT = -1 ;
int REAR = -1 ;

void push(int x){
    stack[++TOP] = x ;
}

int pop(){
    return stack[TOP--] ;
}

void enqueue(int x){
    if ((FRONT == -1) && (REAR == -1))
        FRONT = 0 ;
    queue[++REAR] = x ;
}

int dequeue(){
    return queue[FRONT++] ;
}

void display(){
    for (int i = FRONT ; i <= REAR ; i++)
        printf("%d ",queue[i]) ;
    printf("\n") ;
}

void main()
{
    printf("Enter the no of elements in the queue : ") ;
    scanf("%d", &size) ;
    printf("Enter the elements : ") ; 
    for (int i = 0 ; i < size; i++ ){
        int value ;
        scanf("%d", &value) ;
        enqueue(value) ;
    }
    printf(" => ") ;
    display() ;
    for (int i = 0 ; i < size; i++ )
        push(dequeue()) ;
    for (int i = 0 ; i < size; i++ )
        enqueue(pop()) ;
    printf("Reversed \n => ") ;
    display() ;
}