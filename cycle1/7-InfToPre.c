#include<stdio.h>
#include <string.h>
char expression[50] ;
char invertedexpression[50] ;
char stack[50] ;
char output[50] ;
int i ;
int TOP ;
int len ;

void getExpression(){
    i = 0 ;
    printf("Input The Expression : ") ;
    scanf("%s",expression) ;
    while(expression[i] != '\0' ){
        i++ ;
    }
    len = i ;
}
void invertExpression(){
    int j = len - 1;
    for ( i = 0; i < len ; i++){
        if ( expression[i] == '('){
            invertedexpression[j] = ')' ;
            j-- ;
        }else if (expression[i] == ')'){
            invertedexpression[j] = '(' ;
            j-- ;
        }else{
            invertedexpression[j] = expression[i] ;
            j-- ;
        }
    }
    invertedexpression[len] = ')' ;
}
void push(char x){
    TOP++;
    stack[TOP] = x ;
}
char pop(){
    return( stack[TOP--] ) ;
}
void main(){
    char item ;
    TOP = -1 ;
    getExpression() ;invertExpression() ;
    push('(') ;
    int k = 0 ;
    for( int j = 0 ; j <= len ; j++){
        item = invertedexpression[j] ;
        switch( item ){
            case '+' :
            case '-' :
                while( stack[TOP] != '(' ){
                    output[k] = pop() ;
                    k++ ;
                }
                push(item) ;
                break ;
            case '*' :
            case '/' :
                while( stack[TOP] == '^' || stack[TOP] == '*' || stack[TOP] == '/' ){
                    output[k] = pop() ;
                    k++ ;   
                }
                push(item) ;
                    break ;
            case '^':
                push(item) ;
                break ;
            case '(' :
                push(item) ;
                break ;

            case ')':
                while( stack[TOP] != '(' ){
                    output[k] = pop() ;
                    k++ ;
                }
                pop() ;
                break ;
            default :
                output[k] = item ;
                k++ ;
                break ;
        
        }
    }
    for ( int l = k; l >= 0 ; l--)
        printf("%c",output[l]) ;
    printf("\n") ;
}