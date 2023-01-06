#include<stdio.h>
void sort(int arr[],int n){
	int temp,j ;
	for(int i =0; i< n ;i++){
		temp = arr[i];
		j=i-1 ; 
		while(j >= 0 && arr[j] > temp){
			arr[j+1] = arr[j] ; 
			j-- ;
		}
		arr[j+1] = temp ; 
		j=i+1;
	}
}
void display(int arr[] , int n ){
	printf("sorted array\n") ; 
	for( int i = 0 ; i< n ; i++)	
		printf("%d ",arr[i]) ;
	printf("\n") ; 
}
int main(){
	int arr[50], n ; 
	printf("Enter the no of elements in the array : " ) ; 
	scanf("%d",&n ) ; 
	printf("Enter the elements in the array\n") ; 
	for ( int i = 0 ; i< n ; i++) 
		scanf("%d",&arr[i]) ; 
	sort(arr,n) ;
	display(arr,n) ; 
}
