#include <stdio.h>

// Swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Partition function to find the correct position of the pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choosing the last element as the pivot
    int i = (low - 1);  // Index of smaller element

    // Iterate through the array
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;  // Increment index of smaller element
            swap(&arr[i], &arr[j]);  // Swap the elements at indices i and j
        }
    }
    swap(&arr[i + 1], &arr[high]);  // Swap the pivot with the element at index (i + 1)
    return (i + 1);  // Return the index of the pivot
}

// Quicksort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array into two sub-arrays
        int pi = partition(arr, low, high);

        // Recursive call to quicksort the left and right sub-arrays
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Utility function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Test the quicksort function
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};  // Test array
    int arr_size = sizeof(arr) / sizeof(arr[0]);  // Calculate the size of the array

    printf("Given array is \n");
    printArray(arr, arr_size);

    quickSort(arr, 0, arr_size - 1);  // Call the quickSort function to sort the array

    printf("\nSorted array is \n");
    printArray(arr, arr_size);

    return 0;  // End of the program
}
