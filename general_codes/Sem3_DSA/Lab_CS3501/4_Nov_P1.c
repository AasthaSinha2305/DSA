//Write a program to implement Linear Search and Binary Search
//ROLL NUMBER 1904155

#include <stdio.h>
#include <stdlib.h>
void linear_search(int a[],int,int);
void binary_search(int a[],int,int);

int main(){
    int n,i,*p,ele;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    p = (int*)malloc(n*sizeof(int));
    printf("Enter all the %d elements in the array: ",n);
    for(i=0;i<n;i++){
        scanf("%d",p+i);
    }
    printf("\nEnter the value of the element to search: ");
    scanf("%d",&ele);
    linear_search(p,n,ele);
    binary_search(p,n,ele);
 
    return 0;
}
void linear_search(int a[], int l, int element){
    int index = -1,i;
    printf("\n----------------USING LINEAR SEARCH-------------------\n");
    for(i=0;i<l;i++){
        if(a[i] == element){
            index = i;
            break;
        }
    }
    if(index == -1){
        printf("\nElement not found in the array\n");
    }
    else{
        printf("\narray: ");
        for(i=0;i<l;i++){
            printf("%d ",a[i]);
        }
        printf("\nElement found at index %d (i.e at position %d from left) in nonsorted array\n",index,index+1);
    }
}

void binary_search(int a[], int l, int element){
    printf("\n----------------USING BINARY SEARCH-------------------\n");
    int i,j ,min,temp;
    for(i=0;i<l;i++){
        min = i;
        for(j=i+1;j<l;j++){
            if(a[j]<a[min]){
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    printf("\nSorted array: ");
    for(i=0;i<l;i++){
        printf("%d ",a[i]);
    }
    int low, high ,mid,ans = -1;
    low = 0;
    high = l-1;
    while(low<=high){
        mid = (low+high)/2;
        if(a[mid] < element){
            low = mid + 1;
        }
        else if(a[mid] > element){
            high = mid - 1;
        }
        else{
            ans  = mid;
            break;
        }
    }
    if(ans == -1){
        printf("\nElement is not found in the array\n");
    }
    else{
        printf("\nElement found at index %d (i.e at position %d from left) in sorted array\n",mid,mid+1);
    }

}

