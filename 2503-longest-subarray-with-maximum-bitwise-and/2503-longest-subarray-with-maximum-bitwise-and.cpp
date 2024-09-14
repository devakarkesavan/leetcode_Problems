class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        int cnt = 0,ans = 1;
        for(auto it:nums){
            if(it==maxi){
                cnt+=1;
            }
            else{
                cnt = 0;
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};