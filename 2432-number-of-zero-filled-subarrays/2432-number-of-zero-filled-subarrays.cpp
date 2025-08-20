class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int counter = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                counter++;
            }
            else{
                ans+=(long(counter) * (counter+1)/2);
                counter = 0;
            }
        }
        ans+=(long(counter) * (counter+1)/2);
        return ans;
    }
};