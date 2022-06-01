#include <stdio.h>
#include <stdlib.h>
int main()
{
    int noOfElements;
    printf("Enter number of elements:");
    scanf("%d",&noOfElements);
    printf("\nMemory allocation using Malloc:\n");
    int *ptr1 = (int *)malloc(noOfElements*sizeof(int));
    for (int i = 0;i<noOfElements;i++) printf("Value and Address of block %d is %d and %p\n", i + 1, ptr1[i], &ptr1[i]);

    printf("Memory allocation using Calloc : \n");
    int *ptr2 = (int *)calloc(noOfElements, sizeof(int));
    for (int i = 0; i < noOfElements; ++i) printf("Value and Address of block %d : %d and %p\n", i + 1, ptr2[i], &ptr2[i]);
    free(ptr1);
    free(ptr2);
    return 0;
}