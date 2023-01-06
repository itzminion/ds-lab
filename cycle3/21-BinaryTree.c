#include<stdio.h>
#include<stdlib.h>

struct node{
    int data ; 
    struct node *left , *right ; 
} ; 

struct node *root = NULL ; 
int rear = -1 , front = -1; 
struct node* q[100] ; 
 

void enqueue(struct node *new){
    if (front == -1 || rear == -1 ){
        front = rear = 0 ; 
        q[rear] =new ; 
    }else{
        rear++ ;  
        q[rear] = new ; 
    }
}

struct node* dequeue(){
    if(front == -1 || front > rear){
        return NULL ; 
    }else{
        return q[front++] ; 
    }
}

struct node* create(){
    struct node *new = (struct node*)malloc(sizeof(struct node));
    int n ; 
    scanf("%d",&n) ; 
    if(n== -1)
        return NULL ;
    else{
        new->data = n ; 
        printf("Enter left child of %d : ", n) ; 
        new->left = create();
        printf("Enter right child of %d: ",n);
        new->right = create() ; 
        return new ; 
    }
}

void insert(){
    struct node *temp = root ; 
    struct node *new = (struct node*)malloc(sizeof(struct node));
    front = rear = -1 ; 
    printf("Enter the value to insert: ") ; 
    scanf("%d",&new->data) ; 
    new->left = NULL ; 
    new->right = NULL ; 
    if(root == NULL)
        root = new ; 
    else{
        while(front <= rear){
            if(temp->left == NULL){
                temp->left = new ; 
                return ; 
            }
            if(temp->right == NULL){
                temp->right = new ; 
                return ; 
            }
            if(temp->left != NULL)
                enqueue(temp->left);
            if(temp->right != NULL)
                enqueue(temp->right) ; 
            temp = dequeue() ; 
        }
    }
}

void inorder(struct node *root){
    if (root == NULL)
        return ; 
    inorder(root->left) ; 
    printf("%d ",root->data ) ; 
    inorder(root->right) ; 
}

void preorder(struct node *root){
    if (root == NULL)
        return  ; 
    printf("%d ",root->data) ; 
    preorder(root->left); 
    preorder(root->right) ; 
}

void postorder(struct node *root)
{
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

void delete(int item){
    struct node *temp = root ;
    struct node *del_node = NULL ; 
    front = rear = -1 ; 
    if(root== NULL){
        printf("Empty tree");
        return ; 
    }else{
        enqueue(root);
        while(front<=rear){
            temp= dequeue() ; 
            if(temp->data == item)
                del_node = temp ; 
            if(temp->left != NULL)
                enqueue(temp->left) ; 
            if(temp->right != NULL)
                enqueue(temp->right) ; 
        }
    }
    if(del_node==NULL)
        printf("Not found");
    else{
        del_node->data = temp->data ; 
        struct node *ptr = root ; 
        front = rear = -1 ; 
        if(temp == root)
            root = NULL ; 
        else{
            while(front<= rear){
                if(ptr->left == temp){
                    ptr->left = NULL ;
                    return  ;
                }
                if(ptr->right == temp)
                    ptr->right = NULL ; 
                if(ptr->left != NULL)
                    enqueue(ptr->left) ; 
                if(ptr->right != NULL)
                    enqueue(ptr->right); 
                ptr= dequeue() ;
            }

        }

    }
}

int main(){
    printf("Enter root node : ") ; 
    root = create() ; 
    int choice, x ; 
    while(1){
        printf("\n1: Insert \n2: Inorder \n3: Preorder \n4: Postorder \n5: Delete \nEnter your choice: ");
        scanf("%d",&choice) ; 
        switch(choice){
            case 1:
                insert() ; 
                break ; 
            case 2: 
                printf("Inorder Traversal: ") ; 
                inorder(root) ; 
                break ; 
            case 3:
                printf("Preorder Traversal: ") ; 
                preorder(root) ; 
                break ; 
            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                break; 
            case 5:
                printf("Enter the element you want to delete: ") ; 
                scanf("%d",&x) ; 
                delete(x) ; 
                break ; 
            default: 
                printf("Invalid") ; 
        }
    }
}