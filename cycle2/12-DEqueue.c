#include<stdio.h>
int queue[100], size , choice ;  
int front =-1 , rear = -1 ; 
void enqueueFront(int n){
	if (front  == 0)
		printf("Insertion not Possible at Front \n") ; 
	else if(front == -1 && rear == -1 ){
		front = rear = 0 ; 
		queue[rear] = n ;
	}
	else 
			queue[--front] ; 
}
void enqueueRear(int n){
	if (rear < size -1){
		if (front == -1 && rear == -1) {
			front = rear = 0 ; 
			queue[rear] = n ;
		}else
			queue[++rear] = n ;
	}else{
		printf("\nQueue overflow\n") ;
	}
}


int dequeueFront(){
	if( rear == -1 && front == -1)
		return -1 ; 
	else if( front == rear ){
		int x =front; 
		rear = front = -1 ; 
		return queue[x] ;
	}else
		return queue[front++];
}
int dequeueRear(){
	if ( rear == -1 ) 
		return -1 ;
	int x = rear ; 
	if( front == rear )
		front = rear = -1 ; 
	else
		rear--;
}



void display(){
	if ( front == -1 && rear == -1 )
		printf("Queue is empty \n");
	else 
		for ( int i = front  ; i <= rear ; i++)
			printf("%d ",queue[i] ) ; 
	printf("\n") ;
}

void main(){
	int num ,deq;
	printf("Enter the size of the queue : ") ; 
	scanf("%d",&size ) ; 
	do{
		printf("\n1. EnqueueFront\t2. DequeueFront\t3. EnqueueRear\t4. DequeueRear \t5. Display\t6. Exit\n >> ");
		scanf("%d",&choice) ;
		switch(choice){
			case 1: 
				printf("Enter a value : " ) ; 
				scanf("%d",&num) ; 
				enqueueFront(num);
				break ; 
			case 2: 
				deq = dequeueFront() ; 
				(deq != -1) ?
					printf("%d ",deq): 
					printf("\nQueue underflow \n" ) ;  
				break ;
			case 3: 
				printf("Enter a value : " ) ; 
				scanf("%d",&num) ; 
				enqueueRear(num);
				break ;
			case 4:
				deq = dequeueRear() ; 
				(deq != -1) ?
					printf("%d ",deq): 
					printf("\nQueue underflow \n" ) ;  
				break ;
			case 5: 
				display() ;
				break; 
			case 6: 
				break ;
			default: 
				printf("Invalid entry\n");
		}
	}while(choice != 6) ;
}


		
			
