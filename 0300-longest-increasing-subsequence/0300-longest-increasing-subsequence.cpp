class Solution {
public:
    int fun(int prev, int ind,vector<int>&nums,vector<vector<int>>&dp,int n){
        if(ind==n){
            return 0;
        }
        if(dp[ind][prev+1]!=-1){
            return dp[ind][prev+1];
        }
        int notTake = fun(prev,ind+1,nums,dp,n);
        int take = 0;
        if(prev==-1 || nums[prev]<nums[ind]){
            take = 1+fun(ind,ind+1,nums,dp,n);
        }
        return dp[ind][prev+1] = max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return fun(-1,0,nums,dp,n);
    }
};