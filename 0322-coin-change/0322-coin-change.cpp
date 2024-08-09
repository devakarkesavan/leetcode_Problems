class Solution {
public:
    int fun(int amount,vector<int>&coins,vector<int>&dp){
        if(amount==0){
            return 0;
        }
        if(amount<0){
            return INT_MAX;
        }
        if(dp[amount]!=-1){
            return dp[amount];
        }
        int mini = INT_MAX;
        for(auto it:coins){
            int k = fun(amount-it,coins,dp);
            if(k!=INT_MAX){
                mini = min(k+1,mini);
            }
        }
        return dp[amount] = mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int ans = fun(amount,coins,dp);
        return ans == INT_MAX ? -1 : ans; 
    }
};
