class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> ans(queries.size());
        if(nums.size()==1){
            for(int i=0;i<queries.size();i++){
                ans[i] = true;
            }
            return ans;
        }
        int n = nums.size();
        vector<int> parity(n,0);
        for(int i=1;i<nums.size();i++){
            if(nums[i]%2 == nums[i-1]%2){
                parity[i] = parity[i-1]+1;
            }
            else{
                parity[i] = parity[i-1];
            }
        }
        for(int i=0;i<queries.size();i++){
            int st = queries[i][0];
            int en = queries[i][1];
            int count = parity[en]-parity[st];
            if(count==0){
                ans[i] = true;
            }
            else{
                ans[i] = false;
            }
        }
        return ans;
    }
};