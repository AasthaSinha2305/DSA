// Write a program to implement Sparse Matrix
// 1904155

#include<stdio.h>
#include<stdlib.h>
main()
{
	int i,j,n,m,count=0,k=0;
	int* matrix;
	
	printf("Enter the value of 'n' for n x m matrix : ");
	scanf("%d",&n);
	printf("Enter the value of 'm' for n x m matrix : ");
	scanf("%d",&m);
	printf("Enter the matrix in row major form :-\n");
	
	matrix = (int*)calloc(n*m,sizeof(int));
	for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	scanf("%d",matrix+sizeof(int)*(k++));
	k=0;
	
	for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	if(*(matrix+sizeof(int)*(k++))==0)
	count++;

	if(count>n*m/2)
	{
		printf("\nEntered matrix is a Sparse matrix with %d zero elements out of %d elements.\n",count,m*n);
		printf("Memory efficient representation of this Sparse Matrix is shown below :-\n\n");
		printf("  i (row index) | j (column index) | element(i,j)");
		printf("\n------------------------------------------------\n");
	}
	else
	printf("\nEntered matrix is not a Sparse matrix and have only %d zero elements out of %d elements.\n",count,m*n);
	k=0;
	
	if(count>n*m/2)
	for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	{
		if(*(matrix+sizeof(int)*k)!=0)
		printf("\t%d\t|\t%d\t   |  %d\n",i,j,*(matrix+sizeof(int)*(k++)));
		else
		k++;
	}
}
