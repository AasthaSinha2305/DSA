#include <stdlib.h>
#include <stdio.h>
int linearSearch(int a[],int num,int ele);
int main(){
    int *p,n,i,result,ele;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    p = malloc(n*sizeof(int));
    printf("Enter the elements: ");
    for(i=0; i<n; i++){
        scanf("%d",p +i);
    }
    printf("Enter the number to search: ");
    scanf("%d",&ele);
    result = linearSearch(p,n,ele);
    (result == -1)?printf("Element not found."):printf("Element %d found at index %d (i.e %d element from left).",ele,result,result+1);
    return 0;
}
int linearSearch(int a[],int num,int element){
    int i;
    for(i=0; i<num; i++){
        if(a[i]==element){
            return i;
        }
    }
    return -1;
}