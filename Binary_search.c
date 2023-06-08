#include<stdio.h>
int main()
{
    int array[20], size,i,minimum,maximum,middle,search;
    printf("Enter the array size less then 20:-");
    scanf("%d",&size);

    printf("Enter the array elements :-");
    for ( i = 0; i < size; i++)
    {
        scanf("%d",&array[i]);
    }

    printf("Enter the value you want to search:-");
    scanf("%d",&search);

    minimum=0;
    maximum=size-1;

    while(minimum <= maximum){

    middle =(minimum+maximum)/2;
    if(array[middle]==search)
    {
    printf("%d is found at %d position and %d index",search,middle+1,middle);
    break;
    }

    else if(array[middle] < search)
    minimum=middle + 1;

    else
     maximum = middle - 1 ;
    }
    if (minimum > maximum)
    {
        printf("%d is not found",search);
    }

}
