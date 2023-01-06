#include<stdio.h>
int poly1[2][10], poly2[2][10] , poly3[2][10] ;
int n1 , n2 ;

void input(){
    printf("Enter the Coefficient and Exponent of 1st  polynomial :\n" ) ; 
    for ( int i = 0 ; i < n1 ; i++){
        scanf("%d%d", &poly1[0][i], &poly1[1][i]) ;
    }
    printf("Enter the coefficient and Exponent of 2nd polynomial :\n" ) ; 
    for ( int i = 0 ; i < n2 ; i++ ){
        scanf("%d%d",&poly2[0][i], &poly2[1][i]) ; 
    }
}
void display(){
    printf("1st polynomail\n" ) ; 
    for ( int i = 0 ; i<n1 ; i++ )
        printf("%dX^%d ",poly1[0][i], poly1[1][i]) ;

    printf("\n2nd polynomail\n") ; 
    for ( int i = 0 ; i< n2 ; i++)
        printf("%dX^%d ", poly2[0][i] , poly2[1][i]) ; 

}
void add(){
    int i=0 , j=0 , k=0 ; 
    while(i < n1 && j < n2 ){
        if(poly1[1][i] == poly2[1][j]){
            poly3[1][k] = poly1[1][i] ; 
            poly3[0][k] = poly1[0][i] + poly2[0][j] ; 
            i++ ; 
            j++ ; 
            k++ ;  
        }else if(poly1[1][i] > poly2[1][j]){
            poly3[1][k] = poly1[1][i] ; 
            poly3[0][k] = poly1[0][i] ; 
            i++ ; 
            k++ ; 
        }else{
            poly3[1][k] = poly2[1][j] ; 
            poly3[0][k] = poly2[0][j] ; 
            j++ ; 
            k++ ; 
        }
    }
    while(i < n1){
        poly3[0][k] = poly1[0][i] ;
        poly3[1][k] = poly1[1][i] ; 
        i++ ; 
        k++ ; 
    }
    while(j < n2){
        poly3[0][k] = poly2[0][j] ; 
        poly3[1][k] = poly2[1][j] ; 
        k++ ; 
        j++ ; 
    }

    printf("\nSum of the two polynomials : \n"); 
    int x = (n1 > n2) ? n1 : n2 ; 
    for ( int i = 0 ; i<= x ; i++)
        printf("%dX^%d ",poly3[0][i], poly3[1][i]) ;

}
void main(){
    printf("Enter the no of term in the 1st polynomial : ") ; 
    scanf("%d", &n1 ) ;
    printf("Enter the no of elements in the 2nd polynomial : ") ; 
    scanf("%d", &n2 ) ; 
    input() ; 
    display() ;
    add() ; 
}