#include<stdio.h>
void sort(int arr[], int n ) {
	for ( int i = 0 ; i< n-1 ; i++){
		for (int j = 0; j < n-i-1 ; j++) {
			if (arr[j] > arr[j+1]) {
				arr[j] += arr[j+1] ; 
				arr[j+1] = arr[j] - arr[j+1] ; 
				arr[j] -= arr[j+1] ; 
			}
		}
	}
	printf("\nSorted array\n") ; 
	for ( int i =0 ; i< n ; i++)
		printf("%d ",arr[i]) ; 
	
	printf("\n") ; 
}
int main(){
	int arr[50], n ; 
	printf("Enter the no of the elements in the array : " ) ; 
	scanf("%d",&n) ; 
	printf("Enter the elements in the array\n") ; 
	for ( int i = 0 ; i < n ; i++)
		scanf("%d",&arr[i]) ; 
	sort(arr,n) ; 
	return 0 ; 
}
 
