#include<stdio.h>
int binarySearch(int arr[],int left , int right, int num ){
	/*
	if(right >=1 ){
		int mid = (left+right)/2 ; 
		if (num == arr[mid])
			return mid ; 
		else if (num > arr[mid]) 	
			return binarySearch(arr,mid+1,right,num) ; 
		else
			return binarySearch(arr,left,mid-1,num) ;
	}
	return -1 ;
	*/
	int mid ; 
	while(left < right){
		mid = (left+right)/2 ; 
		if (num == arr[mid])  
			return mid ; 
		else if( num > arr[mid] )
			left = mid ; 
		else 	
			right = mid ; 
	}
	return -1 ; 
}

int search(int arr[], int n ,int num) {
	for ( int i = 0 ; i< n-1 ; i++){
		for (int j = i+1 ; j < n ; j++) {
			if (arr[i] > arr[j]) {
				arr[i] += arr[j] ; 
				arr[j] = arr[i] - arr[j] ; 
				arr[i] -= arr[j] ; 
			}
		}
	}
	for(int i = 0 ; i < n ; i++)
		printf("%d ",arr[i]) ; 
	printf("\n") ;

	return binarySearch(arr,0,n-1,num);
	
}	
	
int main(){
	int arr[50], n ,num ; 
	printf("Enter the no of element  in the array : ") ; 
	scanf("%d",&n) ; 
	printf("Enter the elements in the array\n" )  ; 
	for (int i = 0 ; i< n ; i++) 
		scanf("%d",&arr[i]) ; 
	printf("Enter the no to search : "); 
	scanf("%d",&num ) ; 
	int result = search(arr,n,num) ; 
	if(result == -1) 
		printf("Element not found \n") ; 
	else 
		printf("Element found at position %d \n", result+1) ; 
	return 0 ;
}	
