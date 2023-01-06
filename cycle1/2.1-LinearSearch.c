#include<stdio.h>
int main(){
	int arr[50] , n , num ; 
	printf("Enter the no of elements in the array : " ) ; 
	scanf("%d",&n) ; 
	printf("Enter the elements in the array\n" ) ; 
	for ( int i = 0 ; i < n ; i++)
		scanf("%d",&arr[i] ) ; 
	printf("ENter the element to search : " ) ; 
	scanf("%d" , &num ) ; 
	for (int i = 0 ; i< n ; i++) {
		if(arr[i] == num ) { 
			printf("No is present at position %d \n ",i+1) ; 
			break ; 
		}else if (i==n-1)
			printf("No is not present \n") ; 
	}
}
