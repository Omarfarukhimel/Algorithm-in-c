#include <stdio.h>
#include <limits.h>

// Function to find the minimum number of coins needed to make a given amount
int minCoins(int coins[], int n, int amount)
{
    int dp[amount + 1]; // Array to store the minimum number of coins needed for each amount
    dp[0] = 0; // Base case

    // Initialize all values in dp[] as maximum
    for (int i = 1; i <= amount; i++)
        dp[i] = INT_MAX;

    // Compute the minimum number of coins for all amounts from 1 to amount
    for (int i = 1; i <= amount; i++) {
        // Check each coin denomination
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i) {
                int sub_res = dp[i - coins[j]];
                if (sub_res != INT_MAX && sub_res + 1 < dp[i])
                    dp[i] = sub_res + 1;
            }
        }
    }

    // Return the minimum number of coins needed for the given amount
    return dp[amount];
}

int main()
{
    int coins[] = {1, 5, 10, 25}; // Available coin denominations
    int n = sizeof(coins) / sizeof(coins[0]); // Number of coin denominations
    int amount = 36; // Amount for which we want to make change

    int minCount = minCoins(coins, n, amount);
    printf("\nMinimum number of coins required to make change for $%d is %d\n\n", amount, minCount);

    return 0;
}
