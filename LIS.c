#include <stdio.h>

// Function to calculate the length of the Longest Increasing Subsequence (LIS)
int lis(int arr[], int n) {
    int lis[n]; // Array to store the length of LIS
    int i, j, max = 0;

    // Initialize LIS values for all indexes as 1 (each element is a subsequence of length 1)
    for (i = 0; i < n; i++)
        lis[i] = 1;

    // Compute optimized LIS values in bottom-up manner
    for (i = 1; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1; // If the current element is greater than the previous element and forms a longer subsequence, update the LIS value
        }
    }

    // Pick the maximum of all LIS values
    for (i = 0; i < n; i++) {
        if (lis[i] > max)
            max = lis[i]; // Find the maximum LIS value
    }

    return max; // Return the length of the LIS
}

int main() {
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    int length = lis(arr, n); // Calculate the length of the LIS

    printf("\nLength of LIS: %d\n\n", length); // Print the length of the LIS

    return 0;
}
