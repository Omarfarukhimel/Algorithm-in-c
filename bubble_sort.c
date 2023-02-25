#include<stdio.h>
int main()
{
    int array[100];
    int i,j,size,temp;
    printf("Enter the array size: ");
    scanf("%d",&size);
    printf("Enter the array elements: ");
    for(i=0;i<=size-1;i++)
    {
        scanf("%d",&array[i]);
    }
    for(i=0;i<=size-1;i++)
    {
        for(j=0;j<=size-1-i;j++)
        {
            if(array[j]>array[j+1])
            {
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
    printf("after sorting asending order the elements are:\n ");
    for(i=0;i<=size-1;i++)
        printf("%d ",array[i]);
    return 0;
}
