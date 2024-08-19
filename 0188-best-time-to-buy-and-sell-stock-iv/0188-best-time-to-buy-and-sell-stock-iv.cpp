class Solution {
public:
    int fun(int ind,int buy,int cap,vector<int>&prices,vector<vector<vector<int>>>&dp){
        int n = prices.size();
        if(ind==n || cap==0){
            return 0;
        }
        if(dp[ind][buy][cap]!=-1){
            return dp[ind][buy][cap];
        }
        int profit=0;
        if(buy==0){
            int notpick =0+fun(ind+1,0,cap,prices,dp);
            int pick = -prices[ind] + fun(ind+1,1,cap,prices,dp);
            profit = max(notpick,pick);
        }
        else{
            int notpick = 0 + fun(ind+1,1,cap,prices,dp);
            int pick = prices[ind]+fun(ind+1,0,cap-1,prices,dp);
            profit = max(notpick,pick);
        }
        return dp[ind][buy][cap] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return fun(0,0,k,prices,dp);
    }
};