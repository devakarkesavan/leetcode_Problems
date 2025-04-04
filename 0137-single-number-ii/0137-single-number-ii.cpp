class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0,two = 0;
        for(auto it:nums){
            one = (it^one)&(~two);
            two = (it^two)&(~one);
        }
        return one;
    }
};