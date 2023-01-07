#include<stdio.h>

void sparse(int a[10][10],int a1[10][3],int r,int c){
    int i,j,k=1,ct=0;
    printf("Enter Elements: \n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&a[i][j]);
            if (a[i][j]!=0){
                ct++;
                a1[k][0]=i;
                a1[k][1]=j;
                a1[k][2]=a[i][j];
                k++;
            }        
        }
        printf("\n");
    }
    a1[0][0]=r;
    a1[0][1]=c;
    a1[0][2]=ct;
    printf("Sparse Matrix: \n");
    for(i=0;i<=ct;i++){
        printf("\t");
        for(j=0;j<3;j++){
            printf("%d\t",a1[i][j]);
        }
        printf("\n");
    }
}
void transpose(int a1[][3]){
    int t[10][3];
    t[0][0]=a1[0][1];
    t[0][1]=a1[0][0];
    t[0][2]=a1[0][2];
    int p=1,i,j;
    for(i=0;i<a1[0][1];i++){
        for(j=1;j<=a1[0][2];j++){
            if(a1[j][1]==i){
                t[p][0]=a1[j][1];
                t[p][1]=a1[j][0];
                t[p][2]=a1[j][2];
                p++;
            }
        }
    }
    printf("Transpose Matrix: \n");
    for(i=0;i<=t[0][2];i++){
    printf("\t");
    for(j=0;j<3;j++){
        printf("%d\t",t[i][j]);
    }
    printf("\n");
}
}
void sum(int a[][3],int b[][3]){
    int s[10][3];
    int i,j;
    s[0][0]=a[0][0];
    s[0][1]=a[0][1];
    int m=1,n=1,k=1;
    if (a[0][0]==b[0][0] && a[0][1]==b[0][1]){
        for(i=0;i<=a[0][0];i++){
            for(j=0;j<=a[0][1];j++){
                if ((a[m][0]==i)&&(a[m][1]==j)&&(b[n][0]==i)&&(b[n][1]==j)){
                    s[k][0]=a[m][0];
                    s[k][1]=a[m][1];
                    s[k][2]=a[m][2]+b[n][2];
                    m++;n++;k++;
                }else if ((a[m][0]==i)&&(a[m][1]==j)){
                    s[k][0]=a[m][0];
                    s[k][1]=a[m][1];
                    s[k][2]=a[m][2];
                    m++,k++;
                }else if ((b[n][0]==i)&&(b[n][1]==j)){
                    s[k][0]=b[n][0];
                    s[k][1]=b[n][1];
                    s[k][2]=b[n][2];
                    n++,k++;
                }       
            }       
        }
        s[0][2]=k-1;
        printf("Sum Matrix: \n");
        for(i=0;i<=s[0][2];i++){
            printf("\t");
            for(j=0;j<3;j++)
                printf("%d\t",s[i][j]);
            printf("\n");
        }
    }else
        printf("Invalid Input");
}
int main(){
    int r1,c1,a[10][10],a1[10][3],i,j;
    printf("=====1st Matrix=====\n");
 
    printf("Rows : ");
    scanf("%d",&r1);
    printf("Columns : ");
    scanf("%d",&c1);
 
    sparse(a,a1,r1,c1);
    printf("\n");
 
    transpose(a1);
    int r2,c2,b[10][10],b1[10][3];
 
    printf("--Matrix 2--\n");
    printf("Rows : ");
    scanf("%d",&r2);
    printf("Columns : ");
    scanf("%d",&c2);
 
    sparse(b,b1,r2,c2);
    printf("\n");
 
    transpose(b1);
    printf("=====2nd Matrix=====\n");
    sum(a1,b1);
}