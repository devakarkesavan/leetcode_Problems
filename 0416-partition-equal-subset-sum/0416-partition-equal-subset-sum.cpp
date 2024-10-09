class Solution {
public:
    bool fun(int i,int tar,vector<int>&nums,vector<vector<int>>&dp){
        if(tar==nums[i]){
            return true;
        }
        if(i==0){
            return tar==nums[0];
        }
        if(dp[i][tar]!=-1){
            return dp[i][tar];
        }
        bool notpick = fun(i-1,tar,nums,dp);
        bool pick = false;
        if(tar>=nums[i]){
            pick = fun(i-1,tar-nums[i],nums,dp);
        }
        return dp[i][tar] = pick|notpick;
    }
    bool canPartition(vector<int>& nums) {
        int tar  = 0;
        for(auto it:nums){
            tar+=it;
        }
        if(tar%2==1){
            return false;
        }
        tar/=2;
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(tar+1,-1));
        return fun(n-1,tar,nums,dp);
    }
};