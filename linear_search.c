#include<stdio.h>
int main()
{
    int i,size,search;
    int array[100];
    printf("Enter the array size: ");
    scanf("%d",&size);
    printf("Enter the array elements: ");
    for(i=0;i<size;i++)
    {
        scanf("%d",&array[i]);
    }
    printf("Enter the array element you want to search:");
    scanf("%d",&search);
    for(i=0;i<size;i++)
    {
        if(array[i]==search)
         break;
    }

    if(i < size)
        printf("the element is found at %d position\n",i);
    else
        printf("the elements is not found");
    return 0;
}
