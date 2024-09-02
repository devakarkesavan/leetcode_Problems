class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mpp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int a = nums[i];
            int m = target-a;
            if(mpp.find(m)!=mpp.end()){
                return {mpp[m],i};
            }
            mpp[nums[i]] = i;
        }
        return {};
    }
};