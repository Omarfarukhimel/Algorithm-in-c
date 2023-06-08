#include <stdio.h>

// Merge two subarrays of arr[]
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;  // Size of the left subarray
    int n2 = right - mid;     // Size of the right subarray

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];  // Copy elements from the left portion of arr[]
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];  // Copy elements from the right portion of arr[]

    // Merge the temporary arrays back into arr[]
    i = 0;      // Initial index of first subarray
    j = 0;      // Initial index of second subarray
    k = left;   // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];  // Place the smaller element in arr[]
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge sort algorithm
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;  // Calculate the middle index

        // Recursively divide the array into two halves and sort them
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the two sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {5, 3, 8, 2, 9};  // Test array
    int n = sizeof(arr) / sizeof(arr[0]);  // Calculate the size of the array

    mergeSort(arr, 0, n - 1);  // Call the mergeSort function to sort the array

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);  // Print the sorted array
    }

    return 0;  // End of the program
}
