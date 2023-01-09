#include <stdio.h>
#include <stdlib.h>


void display(int hash[], int n){
    printf("\n");
    printf("index  value\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\n", i, hash[i]);
}
void insert(int hash[], int n){
    int key;
    printf("\nEnter the element\n");
    scanf("%d", &key);
    int h = key % n;
    if (hash[h] == 0){
        hash[h] = key;

        display(hash, n);
    }else{
        for (int i = h + 1; i < n; i++)
            if (hash[i] == 0){
                hash[i] = key;
                display(hash, n);
                return;
            }
        for (int i = 0; i < h; i++)
            if (hash[i] == 0){
                hash[i] = key;
                display(hash, n);
                return;
            }
        printf("\nHash table is full!\n");
    }
}
void main(){
    int size, flag;
    printf("\nEnter the hash table's size : ");
    scanf("%d", &size);
    int *hash = calloc(size, sizeof(int));
    while (1){
        printf("\n\nEnter\t1.Display hash table\t2. Add to hash table\t3. Exit\n >>");
        scanf("%d", &flag);
        switch (flag){
            case 1:
                display(hash, size);
                break;
            case 2:
                insert(hash, size);
                break;
            case 3:
                exit(0);
            default:
                printf("\nInvalid entry!\n");
                break;
        }
    }
}