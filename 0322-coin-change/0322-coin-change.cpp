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
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0){
                dp[0][i] = i/coins[0];
            }
            else{
                dp[0][i] = 1e9;
            }
        }
        for(int ind=1;ind<n;ind++){
            for(int tar=0;tar<=amount;tar++){
                int nottake = dp[ind-1][tar];
                int take = 1e9;
                if(coins[ind]<=tar){
                    take = 1+dp[ind][tar-coins[ind]];
                }
                dp[ind][tar] = min(take,nottake);
            }
        }
        int k =  dp[n-1][amount];
        if(k==1e9){
            return -1;
        }
        return k;
    }
};
