#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct NODE{
	char name[20];
	int num;
	int mark;
	struct NODE *next;
}NODE ;
NODE *head;

void swap(char*, char*) ; 
void display() ; 
void insert() ;
void delete() ; 
void sort() ; 
void search() ; 


void insert(){
	NODE* new;
	char name[20];
	new = malloc(sizeof(NODE));
	if(new != NULL){
		NODE *ptr = head;
		NODE *ptr1=ptr;
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next=new;
		printf("Enter name, rollno, mark of student.\n");
		scanf("%s %d %d",new->name,&new->num,&new->mark);
		new->next=NULL;
	}
}

void display(){
	printf("\n");
	NODE *ptr = head;
	if(ptr->next==NULL){
		printf("List is empty\n");
		return;
	}else{
		printf("NAME\tROLL.NO\tMARKS\n");
		ptr=ptr->next;
		while(ptr!=NULL){
			printf("%s\t%d\t%d\n",ptr->name,ptr->num,ptr->mark);
			ptr=ptr->next;
		}
	}
	printf("\n");
}

void delete(){
	int key;
	printf("Enter which roll no. that should be deleted: ");
	scanf("%d",&key);
	NODE *ptr = head->next;
	NODE *ptr1=head;
	while(ptr->num!=key && ptr!=NULL){
		ptr1=ptr;
		ptr=ptr->next;
	}
	if(ptr!=NULL){
		ptr1->next=ptr->next;
	}
	else{
		printf("key not found !!!\n");
	}
}

void search(){
	int key;
	printf("Enter which roll no. that should be displayed : ");
	scanf("%d",&key);
	NODE *ptr = head->next;
	NODE *ptr1=head;
	while(ptr->num!=key && ptr!=NULL){
		ptr=ptr->next;
	}
	if(ptr!=NULL){
		printf("%s\t%d\t%d\n",ptr->name,ptr->num,ptr->mark);
	}
	else{
		printf("key not found !!!\n");
	}
}

void sort(){
	NODE* ptr=head;
	NODE* temp=head;
	for(NODE* i=ptr->next; i->next!=NULL; i=i->next){
		for(NODE* j=i->next; j!=NULL; j=j->next){
			if(j->num < i->num){
				temp->num=i->num;
				i->num=j->num;
				j->num=temp->num;
				temp->mark=i->mark;
				i->mark=j->mark;
				j->mark=temp->mark;
				strcpy(temp->name,i->name);
				strcpy(i->name,j->name);
				strcpy(j->name,temp->name);
			}
		}
	}
}

void main(){
	head = malloc(sizeof(NODE));
	int choice;
	do{
		printf("\nEnter choice \n1:Insert Details \n2:Delete Details \n3:Search Details \n4:Sort \n5:Display \n6:Exit\n\n");
		printf("Enter the choice : ");
		scanf("%d",&choice);
	
		switch(choice){
			case 1:	insert();
					display();
					break;
			case 2: delete();
					display();
					break;
			case 3: search();
					break;
			case 4: sort();
					display();
					break;
			case 5: display();
					break;
			case 6:	break;
			default:printf("Invalid Choice");
		}
	}
	while(choice != 6);
}