#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[],int num,int element);
int main()
{
    int i,n,ele,result;
    printf("Enter the number of element: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the sorted array: ");
    for(i=0; i< n; i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d",&ele);
    result = binarySearch(a,n,ele);
    (result == -1)?printf("Element not found."):printf("Element %d found at index %d (i.e %d element from left).",ele,result,result+1);
    return 0;
}
int binarySearch(int arr[],int num,int element){
    int low, high, mid,ans = -1;
    low = 0;
    high = num-1;
    while(low<=high){
        mid = (low+high);
        if(arr[mid]<element){
            low = mid + 1;
        }
        else if(arr[mid]>element){
            high= mid-1;
        }
        else{
            return mid;
        }
    }
    return ans;
}