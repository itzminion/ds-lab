#include<stdio.h>
int queue[100], size , choice ;  
int front =-1 , rear = -1 ; 
void enqueue(int n){
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
int dequeue(){
	if( rear == -1 && front == -1)
		return -1 ; 
	else if( front == rear ){
		int x =front; 
		rear = front = -1 ; 
		return queue[x] ;
	}else
		return queue[front++];
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
	int num ;
	printf("Enter the size of the queue : ") ; 
	scanf("%d",&size ) ; 
	do{
		printf("\n1. Enqueue\t2. Dequeue\t3. Display\t4. Exit\n >> ");
		scanf("%d",&choice) ;
		switch(choice){
			case 1: 
				printf("Enter a value : " ) ; 
				scanf("%d",&num) ; 
				enqueue(num);
				break ; 
			case 2: 
				int deq = dequeue() ; 
				(deq != -1) ?
					printf("%d ",deq): 
					printf("\nQueue underflow \n" ) ;  
				break ;
			case 3: 
				display() ;
				break; 
			default: 
				printf("Invalid entry\n");
		}
	}while(choice != 4) ;
}


		
			
