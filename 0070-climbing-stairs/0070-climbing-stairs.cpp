class Solution {
public:
    int fun(int ind,vector<long long int>&dp){
        if(ind<=1){
            return 1;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int first = fun(ind-1,dp);
        int second = fun(ind-2,dp);
        return dp[ind] =  first+second;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,0);
        dp[0] = dp[1] = 1;
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};