class Solution {
public:
    int fun(int prev,int ind,vector<int>&nums,vector<vector<int>>&dp){
        int n = nums.size();
        if(ind==n){
            return 0;
        }
        if(dp[ind][prev+1]!=-1){
            return dp[ind][prev+1];
        }
        int nottake = fun(prev,ind+1,nums,dp);
        int take = 0;
        if(prev==-1 || nums[prev] < nums[ind]){
            take = 1+fun(ind,ind+1,nums,dp);
        }
        return dp[prev+1][ind] = max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // return fun(-1,0,nums,dp);

    for(int ind = n-1; ind >= 0; ind--) {
        for(int prev = ind-1; prev >= -1; prev--) {
            int nottake = dp[ind+1][prev+1];
            int take = 0;
            if(prev == -1 || nums[prev] < nums[ind]) {
                take = 1 + dp[ind+1][ind+1];
            }
            dp[ind][prev+1] = max(take, nottake);
        }
    }

    return dp[0][0];
    }
};