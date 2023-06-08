#include <stdio.h>
#include <string.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find the Longest Common Subsequence (LCS) of two strings
void lcs(char* X, char* Y, int m, int n) {
    int L[m + 1][n + 1]; // Matrix to store the lengths of LCS

    // Build the L[m+1][n+1] table in bottom-up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0; // Initialize the first row and first column as 0
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1; // If current characters are equal, increment the diagonal value
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]); // If not equal, take the maximum of the left and top values
        }
    }

    int length = L[m][n]; // Length of LCS is stored in L[m][n]

    // Allocate memory to store the LCS
    char lcs[length + 1];
    lcs[length] = '\0'; // Set the null character at the end

    // Traverse the L[m+1][n+1] table to find the LCS
    int i = m, j = n;
    while (i > 0 && j > 0) {
        // If current characters in X and Y are equal, it is part of the LCS
        if (X[i - 1] == Y[j - 1]) {
            lcs[length - 1] = X[i - 1];
            i--;
            j--;
            length--;
        }
        // If not equal, then find the larger of two and go in the direction of larger value
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    // Print the LCS
    printf("\nLCS: %s\n\n", lcs);
}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    lcs(X, Y, m, n);

    return 0;
}
