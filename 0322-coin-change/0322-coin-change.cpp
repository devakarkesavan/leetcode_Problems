class Solution {
public:
    // Recursive function with memoization
    int minCoins(int amount, vector<int>& coins, vector<int>& dp) {
        if (amount == 0) {
            return 0; // Base case: 0 coins needed for amount 0
        }
        if (amount < 0) {
            return INT_MAX; // Invalid case: amount cannot be negative
        }
        if (dp[amount] != -1) {
            return dp[amount]; // Return already computed result
        }

        int result = INT_MAX; // Initialize result to a large value
        for (int coin : coins) {
            int res = minCoins(amount - coin, coins, dp);
            if (res != INT_MAX) {
                result = min(result, res + 1); // Take the minimum of current result and new result
            }
        }

        dp[amount] = result; // Store the result in dp table
        return result;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1); // Initialize dp table with -1
        int ans = minCoins(amount, coins, dp); 
        return ans == INT_MAX ? -1 : ans; 
    }
};
