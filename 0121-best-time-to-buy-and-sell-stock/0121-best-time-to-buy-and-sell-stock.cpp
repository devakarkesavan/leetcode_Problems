class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int n = prices.size();
        int maxi = 0;
        for(int i=1;i<n;i++){
            int cost = prices[i]-mini;
            mini = min(mini,prices[i]);
            maxi = max(maxi,cost);
        }
        return maxi;
    }
};