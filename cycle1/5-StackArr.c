#include<stdio.h>
int stack[10] ,top = -1 ,size;

void push(int n) {
	if(top == size -1)
		printf("----------------------------------Stack is full\n\n") ; 
	else  
		stack[++top] = n ;
}
int pop(){
	if(top == -1){
		printf("----------------------------------Stack is empty\n") ; 
		return top ; 
	}
	else 	
		return stack[top--];
}
void display(){
	
	if(top != -1){
		printf("----------------------------------");
		for (int i= top ; i >= 0 ; i--)
			printf("%d ",stack[i] ) ; 
	}else 
		printf("----------------------------------Stack is empty\n") ; 
	printf("\n");
}


void main(){
	int c,n;
	printf("Enter the size of the array : ") ; 
	scanf("%d",&size) ;
	do{
		printf("1. push \n2. pop \n3.display \n4. Exit\n  >> ") ;
		scanf("%d",&c) ; 
		switch(c){
			case 1: 
				printf("Enter a no : ") ;
				scanf("%d",&n) ;
				push(n) ; 
				break ; 
			case 2: 
				int p = pop() ;
				if( p !=  -1)
					printf("----------------------------------%d\n", p) ;
				break ;
			case 3:
				display() ;
				break ; 
			default:
				printf("Invalid entry\n") ;
				c=4 ;
		}
	}while(c != 4) ;
}









				
	
		
