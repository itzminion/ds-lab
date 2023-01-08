#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct NODE{
    int DATA;
    struct NODE* LC;
    struct NODE* RC;
}NODE ;
void preOrder(NODE* ptr){
    if(ptr == NULL)
        printf(" Tree is empty!");
    else{
        printf(" %d", ptr->DATA);
        if(ptr->LC != NULL)
            preOrder(ptr->LC);
        if(ptr->RC != NULL)
            preOrder(ptr->RC);
    }
}
void inOrder(NODE* ptr){
    if(ptr == NULL)
        printf(" Tree is empty!");
    else{
        if(ptr->LC != NULL)
            inOrder(ptr->LC);
            printf(" %d", ptr->DATA);
        if(ptr->RC != NULL)
            inOrder(ptr->RC);
    }
}
void postOrder(NODE* ptr){
    if(ptr == NULL)
        printf(" Tree is empty!");
    else{
        if(ptr->LC != NULL)
            postOrder(ptr->LC);
        if(ptr->RC != NULL)
            postOrder(ptr->RC);
            printf(" %d", ptr->DATA);
    }
}
NODE* succ(NODE* ptr){
    NODE* ptr1 = ptr->RC;
    if(ptr1 != NULL)
        while(ptr1->LC != NULL)
            ptr1 = ptr1->LC;
    return(ptr1);
}
void insertBST(NODE* ptr, int ITEM){
    NODE* ptr1;
    bool flag = false;
    while(ptr != NULL && flag == false){
        if(ITEM < ptr->DATA){
            ptr1 = ptr;
            ptr = ptr->LC;
        }else if(ITEM > ptr->DATA){
            ptr1 = ptr;
            ptr = ptr->RC;
        }else{
            flag = true;
            printf("\n%d already exists!\n", ITEM);
        }
    }
    if(ptr == NULL){
        if(ptr1->DATA < ITEM){
            ptr1->RC = (NODE*) malloc(sizeof(NODE));
            ptr1->RC->LC = NULL;
            ptr1->RC->RC = NULL;
            ptr1->RC->DATA = ITEM;
            printf("\n%d inserted successfully!\n", ITEM);
        }else{
            ptr1->LC = (NODE*) malloc(sizeof(NODE));
            ptr1->LC->LC = NULL;
            ptr1->LC->RC = NULL;
            ptr1->LC->DATA = ITEM;
            printf("\n%d inserted successfully!\n", ITEM);
        }
    }
}
bool deleteBST(NODE* ROOT, int ITEM){
    NODE* ptr = ROOT;
    bool flag = false;
    NODE* parent;
    int CASE;
    while(ptr != NULL && flag == false){
        if(ITEM < ptr->DATA){
            parent = ptr;
            ptr = ptr->LC;
        }else if(ITEM > ptr->DATA){
            parent = ptr;
            ptr = ptr->RC;
        }else
            flag = true;
    }
    if(flag == false){
        return flag;
    }
    if(ptr->LC == NULL && ptr->RC == NULL)
        CASE = 1;
    else
        if(ptr->LC != NULL && ptr->RC != NULL)
            CASE = 3;
        else
            CASE = 2;
    if(CASE == 1){
        if(parent->LC == ptr)
            parent->LC = NULL;
        else
            parent->RC = NULL;
            free(ptr);
    }
    else if(CASE == 2){
        if(parent->LC == ptr)
            if(ptr->LC == NULL)
                parent->LC = ptr->RC;
            else
                parent->LC = ptr->LC;
        else
            if(ptr->LC == NULL)
                parent->RC = ptr->RC;
            else
                parent->RC = ptr->LC;
                free(ptr);
    }else{
        parent = succ(ptr);
        ITEM = parent->DATA;
        deleteBST(ROOT, parent->DATA);
        ptr->DATA = ITEM;
    }
    return flag;
}
void main(){
    NODE* ROOT = NULL;
    NODE* ptr1;int n;
    L:
    printf("\nChoose the operation\n\n");
    printf("1. Insert a node\n");
    printf("2. Delete a node\n");
    printf("3. Inorder traversal\n");
    printf("4. Preorder traversal\n");
    printf("5. Postorder traversal\n");
    printf("6. Exit\n");
    printf(">> ");
    scanf("%d", &n);
    switch(n){
        case 1:
            if(ROOT == NULL){
                ROOT = (NODE*) malloc(sizeof(NODE));
                ROOT->LC = NULL;
                ROOT->RC = NULL;
                printf("\nEnter data: ");
                scanf("%d", &ROOT->DATA);
                printf("\n%d inserted successfully!\n", ROOT->DATA);
            }else{
            printf("\nEnter data: ");
            scanf("%d", &n);
            insertBST(ROOT, n);
            }
            goto L;
    case 2:
        if(ROOT == NULL)
            printf("\nTree is empty!\n");
        else{
            printf("\nEnter the data to be deleted: ");
            scanf("%d", &n);
            if(n == ROOT->DATA){
                if(ROOT->LC == NULL && ROOT->RC == NULL){
                    free(ROOT);
                    ROOT = NULL;
                    printf("\n%d deleted successfully!\n", n);
                }else{
                    if(ROOT->LC != NULL && ROOT->RC != NULL){
                        ptr1 = succ(ROOT);
                        int temp = ptr1->DATA;
                        deleteBST(ROOT, ptr1->DATA);
                        ROOT->DATA = temp;
                        printf("\n%d deleted successfully!\n", n);
                    }else{
                        if(ROOT->LC == NULL){
                            ptr1 = ROOT->RC;
                            free(ROOT);
                            ROOT = ptr1;
                        }else{
                            ptr1 = ROOT->LC;
                            free(ROOT);
                            ROOT = ptr1;
                        }
                        printf("\n%d deleted successfully!\n", n);
                    }
                }
            }else{
                if(deleteBST(ROOT, n))
                    printf("\n%d deleted successfully!\n", n);
                else
                    printf("\n%d not found!\n", n);
            }
        }
        goto L;
    case 3:
        printf("\nInorder :");
        inOrder(ROOT);
        printf("\n");
        goto L;
    case 4:
        printf("\nPreorder :");
        preOrder(ROOT);
        printf("\n");
        goto L;
    case 5:
        printf("\nPostorder :");
        postOrder(ROOT);
        printf("\n");
        goto L;
    case 6:
        exit(0);
    default:
        printf("Invalid entry!\n");
        goto L;
    }
}
