#include<stdio.h>
#include<stdlib.h>

typedef struct NODE{
    int exponent ;
    int coefficient ;
    struct NODE *next ;
} NODE ;

NODE *HEADER_1, *HEADER_2, *HEADER_3 ;
int size1 ;
int size2 ;

void createPoly(NODE *HEADER, int number_of_terms ){
    NODE *new = (NODE*)malloc(sizeof(NODE)) ;
    for (int i = 0; i < number_of_terms; i++){
        int value ;
        printf("Coeff : ") ;
        scanf("%d",&value) ;
        int exp ;
        printf("Expo : ") ;
        scanf("%d",&exp) ;
        new->coefficient = value ;
        new->exponent = exp ;
        if (i == 0){
            HEADER->next = new ;
        }
        if ( i == (number_of_terms - 1)){
            new->next = NULL ;
        }else{
            NODE *ptr = new ;
            new = (NODE*)malloc(sizeof(NODE)) ;
            ptr->next = new ;
        }
    }
}

void display(NODE *HEADER){
    NODE *ptr = HEADER ;
    while (ptr->next != NULL){
        ptr = ptr->next ;
        printf("%dX^%d ", ptr->coefficient, ptr->exponent) ;
        if(ptr->next != NULL){
            printf(" + ") ;
        }
    }
    printf("\n") ;
}

void addPolynomial(NODE *HEADER, int t1, int t2){
    NODE *new = (NODE*)malloc(sizeof(NODE)) ;
    HEADER->next = new ;
    NODE *ptr1 = HEADER_1->next ;
    NODE *ptr2 = HEADER_2->next ;
    NODE *ptr ;
    int i = 0 ;
    int j = 0 ;
    while((i < t1) || (j < t2)){
        if ((i < t1) && (j < t2)){
            while((i < t1) && (j < t2)){
                if ((ptr1->exponent) > (ptr2->exponent)){
                    new->coefficient = ptr1->coefficient ;
                    new->exponent = ptr1->exponent ;
                    ptr1 = ptr1->next ;
                    ptr = new ;
                    new = (NODE*)malloc(sizeof(NODE)) ;
                    ptr->next = new ;
                    i++ ;
                }else if ((ptr1->exponent) < (ptr2->exponent)){
                    new->coefficient = ptr2->coefficient ;
                    new->exponent = ptr2->exponent ;
                    ptr2 = ptr2->next ;
                    ptr = new ;
                    new = (NODE*)malloc(sizeof(NODE)) ;
                    ptr->next = new ;
                    j++ ;
                }else{
                    new->coefficient = ptr1->coefficient + ptr2->coefficient ;
                    new->exponent = ptr1->exponent ;
                    ptr1 = ptr1->next ;
                    ptr2 = ptr2->next ;
                    ptr = new ;
                    new = (NODE*)malloc(sizeof(NODE)) ;
                    ptr->next = new ;
                    i++ ;
                    j++ ;
                }
            }
        }else if (i < t1){
            while(i < t1){
                new->coefficient = ptr1->coefficient ;
                new->exponent = ptr1->exponent ;
                ptr1 = ptr1->next ;
                ptr = new ;
                new = (NODE*)malloc(sizeof(NODE)) ;
                ptr->next = new ;
                i++ ;
            }
        }else if (j < t2){
            while(j < t2){
                new->coefficient = ptr2->coefficient ;
                new->exponent = ptr2->exponent ;
                ptr2 = ptr2->next ;
                ptr = new ;
                new = (NODE*)malloc(sizeof(NODE)) ;
                ptr->next = new ;
                j++ ;
            }
        }
    }
    ptr->next = NULL ;
}

void main(){
    printf("Enter the No of terms in 1st Polynomial : ") ;
    scanf("%d", &size1) ;
    HEADER_1 = (NODE*)malloc(sizeof(NODE)) ;
    createPoly(HEADER_1, size1) ;
    
    printf("Enter the No of terms in 2nd Polynomail : ") ;
    scanf("%d", &size2) ;
    HEADER_2 = (NODE*)malloc(sizeof(NODE)) ;
    createPoly(HEADER_2, size2) ;
    
    printf("Polynomial 1 => ") ;
    display(HEADER_1) ;
    printf("Polynomial 2 => ") ;
    display(HEADER_2) ;
    
    printf("\nThe sum is => ") ;
    HEADER_3 = (NODE*)malloc(sizeof(NODE)) ;
    HEADER_3->next = NULL ;
    addPolynomial(HEADER_3, size1, size2) ;
    display(HEADER_3) ;
}