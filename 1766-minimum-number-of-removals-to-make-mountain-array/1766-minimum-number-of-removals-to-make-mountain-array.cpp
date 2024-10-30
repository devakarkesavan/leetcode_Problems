class Solution {
public:
    int n;
    vector<int> dp;
    inline void LIS(vector<int>& nums) 
    {
        vector<int> L;
        for (int i = 0; i<n; i++) {
            int x=nums[i];
            auto it=lower_bound(L.begin(), L.end(), x);
            if (it==L.end()) L.push_back(x);
            else *it=x;
            dp[i]=L.size();
        }
    }

    int minimumMountainRemovals(vector<int>& nums) {
        n = nums.size();
        if (n <= 3) {
            return 0;
        }
        dp.assign(n, 0);

        LIS(nums);
        vector<int> R;
        int ans=n;
        for (int i=n-1; i>0; i--) {
            int x=nums[i];
            auto it=lower_bound(R.begin(), R.end(), x);
            if (it==R.end()) R.push_back(x);
            else *it=x;
            if (dp[i]>1 && R.size()>1)
                ans=min(ans, n+1-dp[i]-(int)R.size());
        }
        return ans; 
    }
};
