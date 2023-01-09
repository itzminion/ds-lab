#include<stdio.h>
#include<stdlib.h>
int i = 0;
typedef struct NODE{
    int DATA;
    struct NODE* LC;
    struct NODE* RC;
}NODE;

void sortBST(NODE* ptr, int* arr){
    if(ptr->LC != NULL)
    sortBST(ptr->LC, arr);
    arr[i] = ptr->DATA;
    i++;
    if(ptr->RC != NULL)
    sortBST(ptr->RC, arr);
}

void insertBST(NODE* ptr, int ITEM){
    NODE* ptr1;
    while(ptr != NULL){
        if(ITEM <= ptr->DATA){
            ptr1 = ptr;
            ptr = ptr->LC;
        }else if(ITEM > ptr->DATA){
            ptr1 = ptr;
            ptr = ptr->RC;
        }
    }
    if(ptr == NULL){
        if(ptr1->DATA < ITEM){
            ptr1->RC = (NODE*) malloc(sizeof(NODE));
            ptr1->RC->LC = NULL;
            ptr1->RC->RC = NULL;
            ptr1->RC->DATA = ITEM;
        }else{
            ptr1->LC = (NODE*) malloc(sizeof(NODE));
            ptr1->LC->LC = NULL;
            ptr1->LC->RC = NULL;
            ptr1->LC->DATA = ITEM;
        }
    }
}
void main(){
    int* arr;
        int n;
    printf("Enter the array size : ");
    scanf("%d", &n);
    arr = malloc(n*sizeof(int));
    printf("Enter the elements \n > ");
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    NODE* ROOT = (NODE*) malloc(sizeof(NODE));
    ROOT->LC = NULL;
    ROOT->RC = NULL;
    ROOT->DATA = arr[0];
    
    for(int i=1; i<n; i++)
        insertBST(ROOT, arr[i]);
    
    sortBST(ROOT, arr);
    printf("Sorted array: ");
    
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
