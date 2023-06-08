#include <stdio.h>

int main()
{
    int array[100]; // Declare an integer array to store elements
    int i, j, key, size; // Declare integer variables

    printf("Enter the number of elements in the array: ");
    scanf("%d", &size); // Read the size of the array from the user

    printf("Enter the array elements: ");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &array[i]); // Read array elements from the user
    }

    // Insertion sort algorithm to sort the array in ascending order
    for (i = 1; i < size; i++)
    {
        key = array[i]; // Store the current element
        j = i - 1;

        // Move elements greater than key to one position ahead
        while (key < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key; // Place the key at the correct position in the sorted subarray
    }

    printf("Sorted array in ascending order:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]); // Print the sorted array elements
    }
    printf("\n");

    return 0; // End of the program
}
