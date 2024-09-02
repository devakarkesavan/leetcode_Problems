class Solution {
public:
    int fun(int ind,int tar,vector<int>&coins,vector<vector<int>>&dp){
        if(ind==0){
            if(tar%coins[ind]==0){
            return (tar/coins[0]);
            }
            else{
                return 1e9;
            }
        }
        if(dp[ind][tar]!=-1){
            return dp[ind][tar];
        }
        int nottake = fun(ind-1,tar,coins,dp);
        int take = 1e9;
        if(coins[ind]<=tar){
            take = 1+fun(ind,tar-coins[ind],coins,dp);
        }
        return dp[ind][tar] = min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int k =  fun(n-1,amount,coins,dp);
        if(k==1e9){
            return -1;
        }
        return k;
    }
};
