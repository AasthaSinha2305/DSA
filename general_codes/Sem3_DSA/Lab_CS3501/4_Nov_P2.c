#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int [],int);
int main(){
    int n, *p,i,j;
    printf("\nEnter the number of elements: ");
    scanf("%d",&n);
    p = (int *)malloc(n*sizeof(int));
    printf("\nEnter all the %d elements of the array: \n",n);
    for(i=0;i<n;i++){
        scanf("%d",p+i);
    }
    printf("\nThe array before insertion sort: ");
    for(i=0;i<n;i++){
        printf("%d ",*(p+i));
    }
    if(n==0){
        printf("\nlist empty..........\n");
    }
    else{
        insertion_sort(p,n);
    }
    return 0;
}

void insertion_sort(int a[],int l){
    int i, key, j,k;
    for(i=0; i<l; i++){
        key = a[i];
        j = i-1;
        while(key<a[j] && j>=0){
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = key;
    }
    printf("\nThe array after insertion sort: ");
    for(i=0;i<l;i++){
        printf("%d ",a[i]);
    }
}