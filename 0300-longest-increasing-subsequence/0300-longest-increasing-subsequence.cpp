class Solution {
public:
    int fun(int prev,int ind,vector<vector<int>>&dp,vector<int>&nums,int n){
        if(ind==n){
            return 0;
        }
        if(dp[ind][prev+1]!=-1){
            return dp[ind][prev+1];
        }
        int nottake = fun(prev,ind+1,dp,nums,n);
        int take = 0;
        if(prev==-1 || nums[prev] < nums[ind]){
            take = 1+fun(ind,ind+1,dp,nums,n);
        }
        return dp[ind][prev+1] = max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return fun(-1,0,dp,nums,n);
    }
};