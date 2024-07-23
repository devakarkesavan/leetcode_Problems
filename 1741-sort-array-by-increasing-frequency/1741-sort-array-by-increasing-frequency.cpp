class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mpp1;
        for(auto it:nums){
            mpp1[it]++;
        }
        sort(nums.begin(),nums.end(),[&mpp1](int a,int b){
            if(mpp1[a]!=mpp1[b]){
                return mpp1[a] < mpp1[b];
            }
            return a > b;
        });
        return nums;
    }
};