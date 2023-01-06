#include<stdio.h> 
int queue[100], size , choice ;  
int front = -1 , rear = -1 ; 
void enqueue(int val){
	if ( rear == size -1  && front == 0 || front == (rear+1) % size )
		printf("\n\nQueue  overflow \n" ) ; 
	else
		if( front == -1 && rear == -1 ){
			front = rear = 0 ; 
			queue[rear ] = val ; 
		}else{
			rear = (rear + 1) % size ; 
			queue[rear] = val ;  
		}	
}

int dequeue(){
	if ( front == -1 && rear == -1 )
		return -1 ; 
	else if ( front < rear || front > rear && front != size -1) 
		return queue[front++] ; 		
	else if ( front == rear ){
		int val = queue[front] ; 
		front = rear = -1 ;
		return val ; 
	}else if ( front > rear && front == size -1 ){
		int val = queue[front] ; 
		front = (front + 1) % size ; 
		return val ; 
	}
}
void display(){
	int f = front , r = rear ; 
	printf("\n\n") ; 
	for( int i = 0 ; i< 20 ; i++){
		if ( f == -1 && r == -1) 
			break ;
		else if(f < r || f> r &&  f != size -1)
			printf("%d " , queue[f++]) ; 
		else if(f == r){
			printf("%d " , queue[f] ) ; 
			break ; 
		}else if ( f > r && f == size -1 ){
			printf("%d ", queue[f]) ; 
			f = (f+1)%size ; 
		}
	}
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
					printf("\n\nQueue underflow \n" ) ;  
				break ;
			case 3: 
				display() ;
				break; 
			default: 
				printf("Invalid entry\n");
		}
	}while(choice != 4) ;
}

