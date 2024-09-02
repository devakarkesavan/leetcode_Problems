class Solution {
public:
    int check(int ind,vector<int>&dp){
        if(ind ==0){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        return dp[ind] =  ind%2 + check(ind/2,dp);
    }
    vector<int> countBits(int n) {
        vector<int>dp(n+1,-1);
        vector<int>ans(n+1);
        for(int i=0;i<=n;i++){
            ans[i] = check(i,dp);
        }
        return ans;
    }
};