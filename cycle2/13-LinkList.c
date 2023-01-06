#include<stdio.h>
#include<stdlib.h>

int item,key;
struct node{
	int data;
	struct node *next;
};

struct node *head;
struct node *temp;
struct node *ptr;

void insertFront(){
	printf("Enter the item : ");
	scanf("%d",&item);	

	temp = malloc(sizeof(struct node));
	if(head==NULL){
		ptr=head;
		temp->data=item;
		temp->next=NULL;
		head=temp;	
	}
	else{
		ptr=head;
		temp->data=item;
		temp->next=ptr;
		head=temp;
	}
	
}

void insertRear(){
	printf("Enter the item : ");
	scanf("%d",&item);

	temp = malloc(sizeof(struct node));
	temp->data=item;
	temp->next=NULL;

	if(head==NULL){
		head=temp;
	}
	else{
		ptr=head;
		while(ptr->next != NULL){
			ptr=ptr->next;
		}
		ptr->next=temp;
	}

}

void insetAt(){
	printf("Enter the item : ");
	scanf("%d",&item);
	printf("Enter the Position : ");
	scanf("%d",&key);

	temp = malloc(sizeof(struct node));
	temp->data=item;


	if(head==NULL){
		head=temp;
	}
	else{
		ptr=head;
		while((ptr->next != NULL)  && (ptr->data != key)){
			ptr=ptr->next;
		}
		temp->next=ptr->next;
		ptr->next=temp;
	}
}

void deleteFront(){
	if(head==NULL){
		printf("List is Empty");
	}
	else if(head->next==NULL){
		ptr=head;
		item=ptr->data; 
		head=NULL;
		free(ptr);
		printf("Deleted item : %d",item);
	}
	else{
		ptr=head;
		item=ptr->data;
		head=ptr->next;
		free(ptr);
		printf("Deleted item : %d",item);
	}
}

void deleteRear(){
	if(head==NULL){
		printf("List is Empty");
	}
	else if(head->next==NULL){
		ptr=head;
		item=ptr->data;
		head=ptr->next;
		free(ptr);
		printf("Deleted item : %d",item);
	}
	else{
		struct node *ptr1;
		ptr1=NULL;
		ptr=head;

		while(ptr->next != NULL){
			ptr1=ptr;
			ptr=ptr->next;
		}
		item=ptr->data;
		ptr1->next=NULL;
		free(ptr);
		printf("Deleted item : %d",item);
	}

}

void deleteAt(){
	printf("Enter the Key to be delete : ");
	scanf("%d",&key);

	if(head==NULL){
		printf("List is Empty");
	}
	else if(head->data==key){
		ptr=head;
		item=head->data;
		head=NULL;
		free(ptr);
		printf("Deleted item : %d",item);
	}
	else{
		ptr=head;
		struct node *ptr1;
		ptr1=NULL;
		while((ptr->next !=NULL) && (ptr->data !=key)){
			ptr1=ptr;
			ptr=ptr->next;
		}

		if(ptr->data=key){
			ptr1->next=ptr->next;
			item=ptr->data;
			free(ptr);
			printf("Deleted item : %d",item);
		}
		else{
			printf("KEY not Found!");
		}
	}

}

void display(){
	if(head==NULL){
		printf("List is Empty");
	}
	else{
		ptr=head;
		while(ptr != NULL){
			printf("\n%d",ptr->data);
			ptr=ptr->next;
		}
	}
}

void main(){
	int choice;
	

	do{
		printf("\n\nEnter \n1. Insert Front\n2. Insert Rear\n3. InsertAt \n4. Delete Front\n5. Delete Rear\n6. Delete At\n7. Display\n8. Exit");
		printf("\nEnter the Choice >> ");
		scanf("%d",&choice);

		switch(choice){
			case 1:	insertFront();
					display();
					break;
			case 2:	insertRear();
					display();
					break;
			case 3:	insetAt();
					display();
					break;
			case 4:	deleteFront();
					display();
					break;
			case 5:	deleteRear();
					display();
					break;
			case 6:	deleteAt();
					display();
					break;
			case 7:	display();
					break;
			case 8:	break;
			default:printf("Invalid Choice");
		}
	}
	while(choice != 8 );

}
