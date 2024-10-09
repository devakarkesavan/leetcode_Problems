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
        // vector<vector<bool>>dp(n,vector<bool>(tar+1,false));
        vector<bool>curr(tar+1,false),prev(tar+1,false);
        // return fun(n-1,tar,nums,dp);
        // for(int i=0;i<n;i++){
        //     dp[i][0] = true;
        // }
        curr[0] = prev[0] = true;
        if(nums[0]<=tar){
            prev[nums[0]] = true;
        }
        for(int i=1;i<n;i++){
            for(int k=1;k<=tar;k++){
                bool notpick = prev[k];
                bool pick = false;
                if(k>=nums[i]){
                    pick = prev[k-nums[i]];
                }
                curr[k] = pick||notpick;
            }
            prev = curr;
        }
        return  prev[tar];
    }
};