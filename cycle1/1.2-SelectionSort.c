#include<stdio.h>

void sort(int arr[], int n ){ 
	int min,i,j ; 
	for (i = 0 ; i< n-1 ; i++ ){
		min = i ;
		for (j = i+1 ; j < n ; j++){
			if ( arr[j] < arr[min] )
				min = j ; 
		}
		if(min != i){
			arr[i] += arr[min] ; 
			arr[min] = arr[i] - arr[min] ; 
			arr[i] -= arr[min] ; 
		}
	}
	printf("sorted array\n") ; 
	for ( int i = 0 ; i< n ; i++ )
		printf("%d " , arr[i]) ; 
	printf("\n") ; 
}
int main(){
	int arr[50] , n ;
	printf("Enter the no. of elements in the array : " ) ;
	scanf("%d",&n); 
	printf("Ether the elements in the arrary\n" ) ; 
	for ( int i = 0 ; i< n ; i++ ) 
		scanf("%d",&arr[i]) ; 
	
	sort(arr,n) ; 
}
